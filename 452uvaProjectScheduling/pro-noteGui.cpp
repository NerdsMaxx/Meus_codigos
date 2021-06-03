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
	int t; scanf("%d",&t);
	while(t--)
	{
		scan
		
		char c[5];
		cin.getline(c,5);
	}
}
