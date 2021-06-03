#include <iostream>
#include <queue>

typedef std::pair<int,std::pair<int,int>> iii;
#define l first
#define i second.first
#define j second.second

int nvl=0,lnh=0,cln=0;
char dungeon[40][40][40];
int dist[40][40][40];
int z[6]={1,-1,0,0,0,0};
int x[6]={0,0,1,-1,0,0};
int y[6]={0,0,0,0,1,-1};


void bfs(iii org)
{
	for(int k=0;k<nvl;k++)
		for(int h=0;h<lnh;h++)
			for(int g=0;g<cln;g++)
				dist[k][h][g]=1e9;
	
	dist[org.l][org.i][org.j]=0;
	std::queue<iii> fila; 
	fila.push(org);
	
	int flag=0;
	
	while(!fila.empty())
	{	
		iii p=fila.front();
		fila.pop();
		
		for(int k=0;k<6;k++)
		{
			int nl=p.l+z[k];
			int ni=p.i+x[k];
			int nj=p.j+y[k];
			
			if(nl<0||ni<0||nj<0||nl>=nvl||ni>=lnh||nj>=cln)
				continue;
			
			if(dungeon[nl][ni][nj]=='#')
				continue;
					
			if(dist[p.l][p.i][p.j]+1<dist[nl][ni][nj])
			{
				dist[nl][ni][nj]=dist[p.l][p.i][p.j]+1;
				fila.push(std::make_pair(nl,std::make_pair(ni,nj)));
			}
			
			if(dungeon[nl][ni][nj]=='E')
			{
				++flag;
				if(flag==5&&(nl==0||nl==nvl-1)) 
					return;
				else if(flag==6)
					return;
			}
		}
	}
}

int main()
{
	;
	while(scanf("%d%d%d",&nvl,&lnh,&cln)&&(nvl!=0||lnh!=0||cln!=0))
	{
		iii entr,saida;
		for(int k=0;k<nvl;k++)
		{
			for(int h=0;h<lnh;h++)
			{
				for(int g=0;g<cln;g++)
				{
					scanf(" %c",&dungeon[k][h][g]);
				 
					if(dungeon[k][h][g]=='S')
						entr=std::make_pair(k,std::make_pair(h,g)); 
				  
					if(dungeon[k][h][g]=='E')   
						saida=std::make_pair(k,std::make_pair(h,g));
				}
			}
				    
			char c[5];
			std::cin.getline(c,5);
			std::cin.ignore();
		}
		
		bfs(entr);
		if(dist[saida.l][saida.i][saida.j]==1e9)
			printf("Trapped!\n");
		
		else printf("Escaped in %d minute(s).\n",dist[saida.l][saida.i][saida.j]);
	}
}
