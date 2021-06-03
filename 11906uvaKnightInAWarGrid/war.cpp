#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
int R=0,C=0,M=0,N=0;
short int m[150][150];

pair<int,int> funcao()
{	
	if(m[0][0]==-1)
		return make_pair(0,0);
	
	int x[8]={M,N,-M,-N,M,N,-M,-N};
	int y[8]={N,M,-N,-M,-N,-M,N,M};
	int par=0,impar=0;
	
	queue<pair<int,int>> fila;
	fila.push(make_pair(0,0));
	
	while(!fila.empty())
	{
		pair<int,int> p=fila.front();
		fila.pop();
		
		int qtd=0;
		set<pair<int,int>> conj;
		
		for(int i=0;i<8;i++)
		{
			int ni=p.f+x[i];
			int nj=p.s+y[i];
			
			if(ni<0||ni>=R||nj<0||nj>=C)
				continue;
			
			if(m[ni][nj]==-1)
				continue;
			
			if(conj.find(make_pair(ni,nj))==conj.end())
			{
				qtd++;
				conj.insert(make_pair(ni,nj));
			}	
			

			if(m[ni][nj]!=2&&m[ni][nj]!=1)
			{
				fila.push(make_pair(ni,nj));
				m[ni][nj]=1;
			}
		}
		m[p.f][p.s]=2;
		
		if(qtd%2){impar++;}
		else{par++;}
	}
	
	return make_pair(par,impar);
}

int main()
{
	int T=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&R,&C,&M,&N);
		
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				m[i][j]=0;
		
		int qtdw=0;
		scanf("%d",&qtdw);
		for(int i=0,posi=0,posj=0;i<qtdw;i++)
		{
			scanf("%d%d",&posi,&posj);
			m[posi][posj]=-1;
		}
		
		pair<int,int> resp=funcao();
		printf("Case %d: %d %d\n",i+1,resp.f,resp.s);
	}
}
