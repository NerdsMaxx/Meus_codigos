#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adjlist[30];

void addId(string &a,int &b,map<char,int> &id)
{
	for(int i=0;i<(int)a.size();i++)
	{
		if(id.find(a[i])==id.end())
		{
			id[a[i]]=b;
			b++;
		}
	}
}

bool visited[30];
stack<int> s;
void dfs(int u)
{
	visited[u]=1;
	
	for(int i=0;i<(int)adjlist[u].size();i++)
		if(!visited[adjlist[u][i].second])
			dfs(adjlist[u][i].second);
	
	s.push(u);
}


int dijkstra(map<char,int> &id)
{
	for(int i=0;i<(int)id.size();i++)
		if(!visited[i])
			dfs(i);
	
	int dist[30];
	fill(dist,dist+30,1e9);
	dist[s.top()]=0;
	int f;
	while(!s.empty())
	{
		int u=s.top();s.pop();
		if(s.empty()) f=u;
	
		for(int i=0;i<(int)adjlist[u].size();i++)
		{
			pair<int,int> v=adjlist[u][i];
			if(dist[u]+v.first<dist[v.second])
				dist[v.second]=dist[u]+v.first;
		}
	}
	
	return -1*dist[f];
}

void reset()
{
	for(int i=0;i<30;adjlist[i].clear(),i++);
	fill(visited,visited+30,0);
}

int main()
{
	int t=0; cin>>t;
	while(t--)
	{
		reset();
		
		char c[5];
		cin.getline(c,5);
		cin.ignore();

		map<char,int> id;
		string input="";
		int pw=0,i=0;
		while(1)
		{
			getline(cin,input);
			
			if(input=="")
				break;
			
			string u(input.begin(),input.begin()+1);
			string sw(input.begin()+2,input.end());
			int w=stoi(sw);
			string v="";
			if(input[input.size()-1]>='A'&&input[input.size()-1]<='Z')
			{
				int k=3;
				while(input[k]!=' ')
				{
					k++;
				}
				k++;
				string tmp(input.begin()+k,input.end());
				v=tmp;
			}
			if(v==""&&i==0) pw=w;
			
			addId(u,i,id);
			addId(v,i,id);
			
			for(int k=0;k<(int)v.size();k++)
				adjlist[id[v[k]]].push_back(pair<int,int>(-1*w,id[u[0]]));
		}
		int days=dijkstra(id)+pw;
		
		cout<<days<<"\n\n";
	}
}
