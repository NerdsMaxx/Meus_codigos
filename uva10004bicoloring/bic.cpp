#include <bits/stdc++.h>
using namespace std;

int n=0,l=0;
int cor[300];
vector<int> viz[300];

string bfs()
{	
	cor[0]=0;	
	queue<int> fila;
	fila.push(0);
	
	while(!fila.empty())
	{
		int princ=fila.front();
		fila.pop();
		
		for(int &i:viz[princ])
		{
			if(cor[i]==1e9)
			{
				cor[i]=1-cor[princ];
				fila.push(i);
			}
			else if(cor[i]==cor[princ])
			{
				return "NOT BICOLORABLE.";
			}
		}  
	}
	return "BICOLORABLE.";
}

int main()
{
	for(int i=0;i<300;i++)
	{
		viz[i].reserve(300);
	}
	
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cor[i]=1e9;
			viz[i].clear();
		}
			
		scanf("%d",&l);
		int a=0,b=0;
		for(int i=0;i<l;i++)
		{
			scanf("%d%d",&a,&b);
			viz[a].push_back(b);
			viz[b].push_back(a);
		}
		
		string resp=bfs();
		printf("%s\n",resp.c_str());
	}
}
