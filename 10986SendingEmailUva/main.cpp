#include <bits/stdc++.h>
using namespace std;

#define custo first
#define id second

int n=0,m=0,S=0,T=0;
vector< pair<int,int> > viz[20050];
int dist[20050];

void dijkstra()
{
	priority_queue< pair<int,int>,
	vector<pair<int,int>>,
	greater<pair<int,int>> > pq;
	   
	pq.push(make_pair(0,S));
	while(!pq.empty())
	{
		pair<int,int> v=pq.top();
		pq.pop();
		
		if(v.custo>=dist[v.id]) 
			continue;
		  
		dist[v.id]=v.custo;
		
		pair<int,int> v1;
		for(int i=0;i<(int)viz[v.id].size();i++)
	    {
			v1=viz[v.id][i];
		    v1.custo+=v.custo;
		    pq.push(v1);
		}
	}
}

int main()
{
	int N=0,C=0;
	scanf("%d",&N);
	while(N--)
	{
		++C;
		
		scanf("%d %d %d %d",&n,&m,&S,&T);
		
		for(int i=0;i<n;i++)
		{
			dist[i]=1e9;
			viz[i].clear();
		}
		
		int a=0,b=0,c=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			viz[a].push_back(make_pair(c,b));
			viz[b].push_back(make_pair(c,a));
		}
		dijkstra();
		
		printf("Case #%d: ",C);
		if(dist[T]==1e9) printf("unreachable\n");
		else printf("%d\n",dist[T]);
	}
}
