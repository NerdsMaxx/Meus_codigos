#include <bits/stdc++.h>
using namespace std;

#define UNVISITED -1

vector<int> AdjList[150];
int dfslow[150],dfsnum[150],dfsparent[150];
bool articulationvertex[150];
int dfsNumberCounter=0,dfsRoot=0,rootChildren=0;

void articulation(int u) 
{ 
	dfslow[u] = dfsnum[u] = dfsNumberCounter++; 
	for(int j=0; j<(int)AdjList[u].size(); j++)
	{
		int v=AdjList[u][j];
		if(dfsnum[v] == UNVISITED) 
		{
			dfsparent[v] = u;
			
			if (u == dfsRoot)
				rootChildren++;
			
			articulation(v); 

			if(dfslow[v] >= dfsnum[u])
				articulationvertex[u]=true;

			dfslow[u] = min(dfslow[u],dfslow[v]);
		}
		else if(v!=dfsparent[u])
			dfslow[u] = min(dfslow[u],dfsnum[v]);
	}
}

int main()
{
	int N=0;
	scanf("%d",&N);
	while(N)
	{
		dfsNumberCounter=0;
		fill(dfsnum+1,dfsnum+N+1,-1);
		fill(articulationvertex+1,articulationvertex+N+1,false);
		for(int i=1;i<=N;i++)
			AdjList[i].clear();
			
		int place=0;
		scanf("%d",&place);
		int aux=0;
		while(place)
		{
			do
			{
				scanf("%d",&aux);
				AdjList[place].push_back(aux);
				AdjList[aux].push_back(place);
			}
			while(cin.get()!='\n');
			
			scanf("%d",&place);
		}
		
		for(int i=1;i<=N;i++)
		{
			if(dfsnum[i] == UNVISITED)
			{
				dfsRoot=i;
				rootChildren=0;
				articulation(i);
				articulationvertex[dfsRoot] = (rootChildren > 1);
			}
		}
				
		int crit=count(articulationvertex+1,articulationvertex+1+N,true);
		printf("%d\n",crit);
				
		scanf("%d",&N);
	}
}
