#include <bits/stdc++.h>
using namespace std;

#define FIND(v,obj) find(v.begin(),v.end(),obj)

string org="",dest="";
map<string,vector<string>> viz;
map<string,bool> vs;
map<string,int> dist;
stack<string> resp;

void bfs()
{
	dist[org]=0;
	vs[org]=true;
	queue<string> fila;
	fila.push(org);
	while(!fila.empty())
	{
		string x=fila.front();
		fila.pop();
		vs[x]=true;
		for(string &i:viz[x])
		{
			if(vs[i]!=true&&dist[x]+1<dist[i])
			{
				dist[i]=dist[x]+1;	
				fila.push(i);
			}
			else if(vs[i]==true)
			{
				viz[x].erase(FIND(viz[x],i));
			}
		}
	}
}

bool dfs(string s=org,int cont=0)
{
	if(s==dest&&dist[s]==cont)
	{
		resp.push(s);
		return true;
	}
	
	for(string &i:viz[s])
	{
		if(dfs(i,cont+1))
		{
			resp.push(s);
			return true;
		}
	}
	return false;
}


int main()
{
	int nlinks=0;
	while(cin>>nlinks)
	{
		viz.clear();
		dist.clear();
		vs.clear();
		
		while(!resp.empty())
		{
			resp.pop();
		}
		
		string a="",b="";
		for(int i=0;i<nlinks;i++)
		{
			cin>>a>>b;
			viz[a].push_back(b);
			viz[b].push_back(a);
			dist[a]=dist[b]=1e9;
			vs[a]=vs[b]=false;
		}
		cin>>org>>dest;
		
		if(viz.find(org)!=viz.end()&&viz.find(dest)!=viz.end())
		{
			bfs();
			if(dist[dest]!=1e9)
			{
				dfs();
				while(!resp.empty())
				{
					a=resp.top();
					resp.pop();
					if(!resp.empty())
					{
						b=resp.top();
						cout<<a<<' '<<b<<'\n';
					}
				}
				cout<<'\n';
			}
			else cout<<"No route\n\n";
		}
		else cout<<"No route\n\n";
		
	}
}
