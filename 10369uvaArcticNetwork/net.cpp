#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

typedef pair<int,int> ii;
typedef pair<double,ii> dii;

vector<dii> edges;
vector<ii> coord;
vector<bool> withS;
UnionFind UF;

struct UnionFind
{
	int root[1000];

	UnionFind(int n){
		for(int i=0;i<n;i++){
			root[i]=i;
		}
	}

	reset(int n){
		for(int i=0;i<n;i++){
			root[i]=i;
		}
	}

	int find(int x){
		if(root[x]==x)
            return x;
		return root[x] = find(root[x]);
	}

	void unionn(int x,int y){
		int x1=0,y1=0;
		if((x1=find(x))!=(y1=find(y))){
			root[x1]=y1;
		}
	}
	
	bool equal(int x,int y){
		return find(x)==find(y);
	}
	
	bool notequal(int x,int y){
		return find(x)!=find(y);
	}
};

void kruskal()
{
    sort(arestas.begin(),arestas.end());
    int lim=(int)arestas.size();
    
    for (int i=0;i<lim;i++)
    {
        dii a=arestas[i];
        if(UF.notequal(a.ss.ff,a.ss.ss))
			UF.unionn(a.ss.ff, a.ss.ss);
    }
}

void Dminimun(int u)
{
	if()
}

double Dminimun(int p,int s)
{
	int lim=(int)arestas.size(),qtds=s;
	double d=0,w=0;
	dii a1,a2;
	int i=0;
	
	for(;i<lim;i++)
	{
		d=arestas[i].ff;
		for(int j=0;j<lim;j++)
		{
			if(UF.equal())
		}
	}
}

int main (){
	int t=0,cont=0;
	scanf("%d",&t);
	
	while(cont<t)
	{
		int s=0,p=0;
		scanf("%d%d",&s,&p);
		
		coordenadas.clear();
		coordenadas.reserve(p);
		arestas.clear();
		arestas.reserve((p*(p-1))/2);
				
		int x=0,y=0;
		for(int i=0;i<p;i++)
		{
			scanf("%d%d",&x,&y);
			coordenadas.push_back(ii(x,y));
		}
		
		double w=0;
		ii u,v;
		for(int i=0;i<p;i++)
		{
			u=coordenadas[i];
			for(int j=i+1;j<p;j++)
			{
				v=coordenadas[j];
				w=hypot(u.f-v.f,u.s-v.s);
				arestas.push_back(dii(w,ii(i,j)));
			}
		}
		
		UnionFind UF(p);
		printf("%.2lf\n",encontrarD(p,s,UF));
		
		for(int i=0;i<p;i++)
			for(int j=i+1;j<p;j++)
				if(UF.equal(i,j))
					printf("%d %d\n",i,j);
					
		cont+=1;
	}  
}
