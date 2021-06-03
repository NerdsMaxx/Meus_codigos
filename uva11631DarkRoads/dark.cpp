#include <bits/stdc++.h>
using namespace std;

#define maxn 200000

struct UnionFind{
	int pai[maxn];

	UnionFind(int n){
		for(int i=0;i<n;i++){
			pai[i]=i;
		}
	}

	int find(int x){
		if(pai[x]==x) return x;
		return pai[x] = find(pai[x]);
	}

	void unionn(int x,int y){
		int x1=0,y1=0;
		if((x1=find(x))!=(y1=find(y))){
			pai[x1]=y1;
		}
	}
};

#define custo first
#define a second.first
#define b second.second

pair<int, pair<int, int> > arestas[maxn];
int nv, na;

int kruskal(){
    sort(arestas, arestas+na);
    int valor = 0;
    UnionFind UF(nv);
    pair<int, pair<int, int> >  art;
    for (int i = 0; i < na; i++)
    {
        art=arestas[i];
        if (UF.find(art.a) != UF.find(art.b))
        {
            valor += art.custo;
            UF.unionn(art.a, art.b);
        }
    }
    return valor;
}

int main()
{
	int valorTotal;
	while(scanf("%d%d",&nv,&na)&&(nv!=0||na!=0))
	{
		valorTotal=0;
		
		for(int i=0;i<na;i++)
		{
			scanf("%d%d%d",&arestas[i].a,&arestas[i].b,&arestas[i].custo);
			valorTotal+=arestas[i].custo;
		}
			
		printf("%d\n",valorTotal-kruskal());
	}
}
