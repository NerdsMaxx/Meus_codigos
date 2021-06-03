#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> mtz;
#define custo first
#define i second.first
#define j second.second


mtz m[1000][1000];
int dist[1000][1000],nl=0,nc=0;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

void dijkstra(int io=0,int jo=0)
{
	for(int z=0;z<nl;z++)
		for(int k=0;k<nc;k++)
			dist[z][k]=1e9;
	   
	priority_queue< mtz,
	vector<mtz>,
	greater<mtz> > pq;
	   
	pq.push(make_pair(m[io][jo].custo,make_pair(io,jo)));
	while(!pq.empty())
	{
		mtz v=pq.top();
		pq.pop();
		
		if(v.custo>=dist[v.i][v.j])
			continue;
		  
		dist[v.i][v.j]=v.custo;
		
		mtz v1;
		for(int z=0;z<4;z++)
	    {
			int ni=v.i+x[z];
			int nj=v.j+y[z];
			if(ni>=0&&nj>=0&&ni<nl&&nj<nc)
			{
				v1.custo = m[ni][nj].custo + v.custo;
				v1.i=ni;
				v1.j=nj;
				pq.push(v1);
			}
		}
	}
}

int main()
{
	int nt=0;
	scanf("%d",&nt);
	while(nt--)
	{
		scanf("%d %d",&nl,&nc);
		
		for(int z=0;z<nl;z++)
		{
		  for(int k=0;k<nc;k++)
		  {
		    scanf("%d",&m[z][k].custo);
		    m[z][k].i=z;
		    m[z][k].j=k;
		  }
		}
		    
		dijkstra();
		    
		printf("%d\n",dist[--nl][--nc]);
	}
	
}
