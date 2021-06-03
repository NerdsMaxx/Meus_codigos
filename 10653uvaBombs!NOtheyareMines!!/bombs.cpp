#include <iostream>
#include <queue>
#define pii std::pair<int,int>
#define f first
#define s second

int R=0,C=0;
bool mapa[1000][1000];
int dist[1000][1000];

int bfs(pii o,pii d){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			dist[i][j]=1e9;}}
			
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
			
	int stop=(d.f>0)+(d.s>0)+(d.f<R-1)+(d.s<C-1);
	for(int i=0;i<4;i++){
		int ni=d.f+x[i];
		int nj=d.s+y[i];
		if(ni>=0&&nj>=0&&ni<R&&nj<C){
			stop=stop-(!mapa[ni][nj]);
		}
	}
	
			
	dist[o.f][o.s]=0;
	std::queue<pii> fila;
	fila.push(o);
	while(!fila.empty()){
		pii p=fila.front();
		fila.pop();
		
		for(int i=0;i<4;i++){
			int ni=p.f+x[i];
			int nj=p.s+y[i];
			
			if(ni>=0&&nj>=0&&ni<R&&nj<C){
				if(mapa[ni][nj]!=false&&dist[p.f][p.s]+1<dist[ni][nj]){
					dist[ni][nj]=dist[p.f][p.s]+1;
					fila.push(std::make_pair(ni,nj));
				}
				
				if(ni==d.f&&nj==d.s){
					stop--;
					if(stop==0){
						return dist[d.f][d.s];
					}
				}
			}
		}
	}
	
	return 0;
}

int main(){
	while(scanf("%d %d",&R,&C)&&(R!=0||C!=0)){
		
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				mapa[i][j]=true;}}
		
		
		int x1=0,x2=0,x3=0,x4=0;
		scanf("%d",&x1);
		for(int i=0;i<x1;i++){
			scanf("%d%d",&x2,&x3);
			for(int j=0;j<x3;j++){
				scanf("%d",&x4);
				mapa[x2][x4]=false;}}
				
		pii o,d;
		scanf("%d%d",&o.f,&o.s);
		scanf("%d%d",&d.f,&d.s);
		
		printf("%d\n",bfs(o,d));
	}
}
