#include <bits/stdc++.h>

#define maxn 1000000

std::map <std::string,int> id;
int qtd=0;


struct UnionFind{
	int pai[maxn];
	int tam[maxn];
	
	UnionFind(){
		for(int i=0;i<maxn;i++){
			pai[i]=i;
			tam[i]=1;
		}
	}
	
	int find(int x){
		if(pai[x]==x) return x;
		return pai[x]=find(pai[x]);
	}
	
	void unionn(int x,int y){
		int x1=0,y1=0;
		if((x1=find(x))!=(y1=find(y))){ 
			pai[x1]=y1;
			tam[y1]+=tam[x1];
		}
	}
};

int main(){
	int nt=0;
	scanf("%d",&nt);
	
	while(nt--){
		int na=0;
		scanf("%d",&na);
		
		std::string a="",b="";
		int i=0;
		UnionFind r;
		while(na--){
			
			
			std::cin>>a>>b;
			
			if(!id.count(a)){
				id[a]=i;
				++i;
		    }
			if(!id.count(b)){
				id[b]=i;
				++i;
			}
			
			r.unionn(id[a],id[b]);
			printf("%d\n",r.tam[r.find(id[a])]);
		}
		
		id.clear();
	}
}
