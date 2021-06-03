#include <bits/stdc++.h>
using namespace std;

#define maxn 1000000

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



int main(){
	int nt=0,i=0,j=0;
	char str[20],op;
	scanf("%d",&nt);
	cin.getline(str,20);
	cin.ignore();
	while(nt--){
		int nv=0,ns=0,nins=0;
		
		scanf("%d ",&nv);
		UnionFind r(nv);
		
		while(cin.getline(str,1010) && strlen(str)!=0){
			sscanf(str,"%c %d %d",&op,&i,&j);
			
			if(op=='c') r.unionn(i,j);
		    else if(op=='q'){
		        if(r.find(i)==r.find(j)) ns++;
		        else nins++;
		   }
		}
		
		printf("%d,%d\n",ns,nins);
		if(nt!=0) printf("\n");
	}
}
