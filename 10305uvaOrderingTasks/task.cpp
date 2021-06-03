#include <bits/stdc++.h>
using namespace std;

int n=0,m=0;
vector<int> viz[200];
bool vis[200];
stack<int> pilha;

void dfs(int u)
{
	vis[u]=true;
	
	for(int &v:viz[u])
		if(!vis[v])
		   dfs(v);
		   
    pilha.push(u);
}

int main()
{
	scanf("%d%d",&n,&m);
	while(n!=0||m!=0)
	{
		for(int i=0;i<n;i++)
		{
			viz[i].clear();
			vis[i]=false;
		}
		
		int u=0,v=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			viz[u-1].push_back(v-1);
		}
		
		for(int i=0;i<n;i++)
			if(!vis[i])
				dfs(i);
				
	    while(!pilha.empty())
	    {
			printf("%d ",pilha.top()+1);
			pilha.pop();
			
			if(pilha.size()==1)
				break;
		}
		
		if(!pilha.empty())
		{
			printf("%d\n",pilha.top()+1);
			pilha.pop();
		}

		scanf("%d%d",&n,&m);
	}
}
