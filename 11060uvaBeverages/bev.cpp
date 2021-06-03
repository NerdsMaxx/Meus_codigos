#include <bits/stdc++.h>
using namespace std;

int N=0,M=0,cont=1;
vector<vector<int>> viz;
vector<int> in_degree;
map<string,int> id;
map<int,string> str;
vector<string> resp;

void khan()
{
	priority_queue<int, vector<int>, greater<int>> fila;
	for(int i=0;i<N;i++)
		if(in_degree[i]==0)
			fila.push(i);
	
	while(!fila.empty())
	{
		int x=fila.top();
		fila.pop();
		resp.push_back(str[x]);
		
		for(int &i:viz[x])
		{
			if(--in_degree[i]!=0)
				continue;
			
			fila.push(i);
		}
	}
}

int main()
{
	while(cin>>N)
	{
		viz.clear();
		viz.resize(N);
		in_degree.clear();
		in_degree.resize(N,0);
		id.clear();
		str.clear();
		resp.clear();
		resp.reserve(N);
		
		string aux="";
		for(int i=0;i<N;i++)
		{
			cin>>aux;
			id[aux]=i;
			str[i]=aux;
			in_degree[i]=0;
		}
		
		cin>>M;
		string u="",v="";
		for(int i=0;i<M;i++)
		{
			cin>>u>>v;
			viz[id[u]].push_back(id[v]);
			in_degree[id[v]]++;
		}
		
		khan();
		
		cout<<"Case #"<<cont<<
		": Dilbert should drink beverages in this order: ";
	    for(int i=0;i<N-1;i++)
			cout<<resp[i]<<' ';
			
		cout<<resp[N-1]<<".\n\n";
		
		++cont;
	}
}
