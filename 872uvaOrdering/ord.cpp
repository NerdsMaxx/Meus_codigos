#include <bits/stdc++.h>
using namespace std;

map<char,string> viz;
map<char,bool> vis;

bool eciclo(char u)
{
	if(vis[u]==1)
		return 1;
		
	vis[u]=1;
	
	bool resp=0;
	for(char &v:viz[u])
	{
		resp=eciclo(v);
		
		if(resp)
			return 1;
	}
	
	vis[u]=0;
	return 0;
}

bool valido(string &a)
{
	int lim=(int)a.size();
	int i=0;
	for(;i<lim;i++)
	{
		char aux=a[i];
		int limviz=(int)viz[aux].size();
		int j=0;
		if(!viz[aux].empty())
		{
			for(;j<limviz;j++)
			{
				int k=0;
				for(;k<i;k++)		
					if(a[k]==viz[aux][j])
						break;
					
				if(k==i)
					break;
			}
		}
		if(j!=limviz)
			break;
	}
	if(i==lim)
		return true;
			
	return false;
}

void imprimir(string &a)
{
	int lim=(int)a.size();
	int i=0;
	for(;i<lim-1;i++)
		printf("%c ",a[i]);
	
	printf("%c\n",a[i]);
}

int main()
{
	int t=0;
	scanf("%d",&t);
	
	char c[5];
	cin.getline(c,5);
	cin.ignore();
	while(t--)
	{
		viz.clear();
		vis.clear();
		
		char ch;
		string princ="";
		do{
			scanf(" %c",&ch);
			vis[ch]=0;
			princ+=ch;
		}while(cin.get()!='\n');
		
		string aux="";
		do{
			cin>>aux;
			viz[aux[2]]+=aux[0];
		}while(cin.get()!='\n');
		
		bool ecicloo=0;
		for(pair<char,bool> &&i:vis)
		{
			if(eciclo(i.first))
			{
				ecicloo=1;
				break;
			}
		}
		
		if(ecicloo)
		{
			printf("NO\n\n");
			continue;
		}
		
		sort(princ.begin(),princ.end());
		do{
			if(valido(princ))
				imprimir(princ);
		}while(next_permutation(princ.begin(),princ.end()));
		printf("\n");
	}
	
}
