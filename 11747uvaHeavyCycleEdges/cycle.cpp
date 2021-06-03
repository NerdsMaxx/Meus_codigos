#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;//certo

vector<bool> taken;//certo
priority_queue<ii> pq;//certo
priority_queue<int> resultw;//certo

vector<vector<ii>> AdjList;//certo

void process(int vtx)
{
	taken[vtx]=1;//certo
	
	for(int j=0;j<(int)AdjList[vtx].size();j++)
	{
		ii v=AdjList[vtx][j];//certo
		
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));//certo
	}
}

int main()
{
	int n=0,m=0;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		taken.assign(n,0);
		vector<ii> aux;
		aux.reserve(n);
		AdjList.assign(n,aux);
		
		int u=0,v=0,w=0,first=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			AdjList[u].push_back(ii(v,w));
			AdjList[v].push_back(ii(u,w));
			
			if(i==0)  first=u;
		}
		
		process(first);
				
		while(!pq.empty())
		{
			ii front=pq.top(); pq.pop();
			u=-front.second, w=-front.first;
			
			if(!taken[u]) process(u);
			else resultw.push(-w);
			
			if(pq.empty())
			{
				int i=0;
				for(;i<n&&(AdjList[i].empty()||taken[i]);i++);
				if(i<n)  process(i);
			}
		}
		
		if(resultw.empty()) printf("forest\n");
		
		while(!resultw.empty())
		{
			printf("%d",-resultw.top());
			
			if(resultw.pop(),resultw.empty()) printf("\n");
			else printf(" ");
		}
	}
}
