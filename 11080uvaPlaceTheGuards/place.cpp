#include <bits/stdc++.h>
using namespace std;

int T=0,v=0,e=0;
int cor[300];
vector<int> viz[300];

int bfs(int x)
{	
	int qtd[2]={0,0};
	cor[x]=0;
	qtd[cor[x]]=1;	
	queue<int> fila;
	fila.push(x);
	
	while(!fila.empty())
	{
		int princ=fila.front();
		fila.pop();
		
		for(int &i:viz[princ])
		{
			if(cor[i]==1e9)
			{
				cor[i]=1-cor[princ];
				fila.push(i);
				qtd[cor[i]]++;
			}
			else if(cor[i]==cor[princ])
				return -1;
		}  
	}
	
	if(qtd[1]==0)
		return qtd[0];
	else
		return min(qtd[0],qtd[1]);
}

int main()
{
	for(int i=0;i<300;i++)
		viz[i].reserve(300);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&v,&e);
		
		for(int i=0;i<v;i++)
		{
			viz[i].clear();
			cor[i]=1e9;
		}
		
		int f=0,t=0; 
		for(int i=0;i<e;i++)
		{
			scanf("%d%d",&f,&t);
			viz[f].push_back(t);
			viz[t].push_back(f);
		}
		
		int x=0,soma=0;
		for(int i=0;i<v;i++)
		{
			if(cor[i]==1e9)
			{
				x=bfs(i);
				if(x==-1)
				{
					soma=x;
					break;
				}
				else
					soma+=x;
			}
		}
		
		printf("%d\n",soma);
	}
}
