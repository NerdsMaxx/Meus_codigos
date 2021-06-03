#include<bits/stdc++.h>
using namespace std;

vector<int> viz[101];
bool nvis[101];
bool incsl=true;
int cons[101];

void dfs(int i,int v)
{
	if (nvis[i])
	{
		nvis=0;
		if(i==v) 
		  incsl=false;
		else
		{
			int lim=(int)viz[i].size();
			for(int j=0;j<lim;j++)
			dfs(i,v);
		}
	}
}

int main()
{
	int nv=0;
	scanf("%d",&nv);
	while(nv)
	{
		int i=nv;
		while(i--)
		{
			int in=0;
			scanf("%d",&in);
			int fn=0;
			scanf("%d",&fn);
			while(fn)
			{
				viz[in].push_back(fn);
				scanf("%d",&fn);
			}
		}
	    cin.ignore;
	    int nc=0;
		scanf("%d",&nc);
		for(int i=0;i<nc;i++) 
		 scanf("%d",&cons[i]);
		 
		for(int i=0;
		
		scanf("%d",&nv);
	}
}
