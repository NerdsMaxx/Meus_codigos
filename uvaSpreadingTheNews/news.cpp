#include <bits/stdc++.h>

int E=0,origem=0;
std::vector<int> amg[3000];
int dist[3000];

void bfs()
{
	for(int i=0;i<E;i++){
		dist[i]=1e9;
	}
	
	std::queue<int> fila;
	fila.push(origem);
	dist[origem]=0;
	while(!fila.empty())
	{
		int x=fila.front();
		fila.pop();
		
		unsigned lim=amg[x].size();
		int x1=0;
		for(unsigned i=0;i<lim;i++){
			x1=amg[x][i];
			if(dist[x]+1<dist[x1]){
				dist[x1]=dist[x]+1;
				fila.push(x1);
			}
		}
	}
}

std::pair<int,int> resp()
{
	std::map<int,int> qtd;
	
	for(int i=0;i<E;i++){
		if(dist[i]!=1e9&&i!=origem){
			qtd[dist[i]]++;
		}
	}
	
	std::pair<int,int> r;
	r=std::make_pair(0,0);
	
	if(qtd.empty()){
		return r;
	} 
	
	for(auto i:qtd){
		if(i.second>r.second){
			r=i;
		}
	}
	return r;
}

int main()
{
	scanf("%d",&E);
	for(int i=0;i<E;i++){
		int N=0;
		scanf("%d",&N);
		amg[i].resize(N);
		
		for(int j=0;j<N;j++){
			scanf("%d",&amg[i][j]);
		}
	}
	
	int T=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&origem);
		bfs();
		std::pair<int,int> result=resp();
		
		if(result.first==0){
			printf("0\n");
		}
		else{
			printf("%d %d\n",result.second,result.first);
		}
	}
}
