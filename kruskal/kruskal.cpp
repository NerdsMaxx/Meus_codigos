#include <bits/stdc++.h>
using namespace std;

#define maxn 1000000
#define maxa 1000000

struct UnionFind{
	int pai[maxn];
	
	UnionFind(int n){
		for(int i=0;i<=n;i++) pai[i]=i;
	}
	
	int find(int x){
		if(pai[x]==x) return x;
		return pai[x]=find(pai[x]);
	}
	
	void unionn(int x,int y){
		if(find(x)!=find(y)) pai[find(x)]=find(y);
	}
};

struct arestas{
	int custo=0,a=0,b=0;
};
int n=0;
vector<arestas> aresta;

int kruskal(){
	UnionFind uf(n);
	int custo=0;
	sort(aresta.begin(),aresta.end());
	for(int i=0;i<(int)aresta.size();i++)
	{
		if(uf.find(aresta[i].a)!=uf.find(aresta[i].b)){
			custo+=aresta[i].custo;
			uf.unionn(aresta[i].a,aresta[i].b);
		}
	}
	return custo;
}

