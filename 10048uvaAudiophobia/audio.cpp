#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<bool> taken;
priority_queue<iii> pq;

vector<vector<ii>> AdjList;
vector<vector<bool>> allowed;
vector<int> maxx;

void reset(int n)
{
	taken.assign(n,0);
	allowed.assign(n,vector<bool>(n,1));
	
	vector<ii> aux;
	aux.reserve(n);
	AdjList.assign(n,aux);
}


void process(int u)
{
	taken[u]=1;
	
	for(int i=0;i<(int)AdjList[u].size();i++)
	{
		ii v=AdjList[u][i];
		
		if(!taken[v.first])
			pq.push(iii(-v.second,ii(-v.first,-u)));
	}
}

void bfs(int u,int d)
{
	queue<int> q;
	q.push(u);
	
	while(!q.empty())
	{
		u=q.front(),q.pop();
		taken[u]=1;
		
		if(u==d)
			break;
		
		for(int i=0;i<(int)AdjList[u].size();i++)
		{
			ii v=AdjList[u][i];
			
			if(!taken[v.first]&&allowed[u][v.first]==1){
				q.push(v.first), maxx[v.first]=max(maxx[u],v.second);
			}
		}
	}
}

int main()
{
	int C=0,S=0,Q=0,counter=1;
	scanf("%d%d%d",&C,&S,&Q);
	while(C||S||Q)
	{
		reset(C);
		
		int u=0,v=0,w=0,first=0;
		for(int i=0;i<S;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			AdjList[--u].push_back(ii(--v,w));
			AdjList[v].push_back(ii(u,w));
			
			if(i==0)  first=u;
		}
		
		process(first);
		
		while(!pq.empty())
		{
			iii front=pq.top(); pq.pop();
			u=-front.second.first, v=-front.second.second, w=-front.first;
			
			if(!taken[u]) process(u);
			else{ allowed[u][v]=0;
				  allowed[v][u]=0; }
			
			if(pq.empty())
			{
				int i=0;
				for(;i<C&&(AdjList[i].empty()||taken[i]);i++);
				if(i<C)  process(i);
			}
		}
		
		vector<int> result;
		result.reserve(Q);
		for(int i=0;i<Q;i++)
		{
			taken.assign(C,0);
			maxx.assign(C,0);
			
			scanf("%d%d",&u,&v);
			bfs(--u,--v);
			result.push_back(maxx[v]);
		}
		
		printf("Case #%d\n",counter);
		for(int i=0;i<Q;i++)
		{
			if(result[i]!=0){
				printf("%d\n",result[i]);
			}else {printf("no path\n");}
		}
		
		scanf("%d%d%d",&C,&S,&Q);
		
		if(C||S||Q)
		{
			printf("\n");
			counter++;
		}
	}
}
