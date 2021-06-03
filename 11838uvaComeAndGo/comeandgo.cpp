#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1
bool dfs_num[3000];
vector<int> adj_list[3000];
vector<int> adj_list_t[3000];
vector<int> S;

void reset(int &n)
{
	memset(dfs_num,UNVISITED,sizeof(dfs_num));
	
	for(int i=0;i<n;i++)
	{
		adj_list[i].clear(); adj_list[i].reserve(n);
		adj_list_t[i].clear(); adj_list_t[i].reserve(n);
	}
	S.clear(); S.reserve(n);
}

void kosaraju(int &u,bool pass)
{
	dfs_num[u]=VISITED;
	vector<int> neighbor;
	if(pass==0) neighbor=adj_list[u];
	else neighbor=adj_list_t[u];
	
	for(int &v:neighbor)
		if(dfs_num[v]==UNVISITED)
			kosaraju(v,pass);
			
	S.push_back(u);
}

int main()
{
	int N=0,M=0;
	while(scanf("%d%d",&N,&M)&&(N||M))
	{	
		reset(N);
		
		int V=0,W=0,P=0;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&V,&W,&P);
			adj_list[--V].push_back(--W);
			adj_list_t[W].push_back(V);
			
			if(P==2)
			{
				adj_list[W].push_back(V);
				adj_list_t[V].push_back(W);
			}
		}
		
		for(int i=0;i<N;i++)
			if(dfs_num[i]==UNVISITED)
				kosaraju(i,0);
				
				
		memset(dfs_num,UNVISITED,sizeof(dfs_num));
		int numSCC=0;
		for(int i=N-1;i>=0;i--)
		{
			if(dfs_num[S[i]]==UNVISITED)
			{
				if(numSCC)
				{
					numSCC=0;
					break;
				}
					
				kosaraju(S[i],1);
				++numSCC;
			}
		}
		
		printf("%d\n",numSCC);
	}
}
