#include <bits/stdc++.h>
using namespace std;

int M=0,N=0;
char mapa[30][30];
bool vis[30][30];
char l;

int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

void dfs(int i,int j,int &qtdl)
{
	vis[i][j]=1;
		
	for(int k=0;k<4;k++)
	{
		int ni=i+x[k];
		int nj=j+y[k];
		
		if(ni<0||ni>=M)
			continue;
		
		if(nj==N)
			nj=0;
		else if(nj==-1)
			nj=N-1;
			
		if(mapa[ni][nj]!=l||vis[ni][nj])
			continue;
			
		qtdl++;		
		dfs(ni,nj,qtdl);
	}
}

int main()
{
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++)
				{scanf(" %c",&mapa[i][j]);
				 vis[i][j]=0;}}
		
		int posi=0,posj=0;
		scanf("%d%d",&posi,&posj);
		
		l=mapa[posi][posj];
		
		int qtdl=0;
		dfs(posi,posj,qtdl);
		
		qtdl=0;
		int maxn=0;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(!vis[i][j]&&mapa[i][j]==l){
					qtdl++;
					dfs(i,j,qtdl);
					maxn=max(qtdl,maxn);
					qtdl=0;}}}
		
		printf("%d\n",maxn);
		
		char c[4];
		cin.getline(c,4);
		cin.ignore();
	}
}
