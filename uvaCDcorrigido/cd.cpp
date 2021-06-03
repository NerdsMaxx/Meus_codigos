#include <bits/stdc++.h>
using namespace std;

int N,nt,maxx=0;
int tracks[30];
deque<int> resp;

void backtracking(int i,int soma,queue<int> aux)
{
	if(i<nt)
	{	
		queue<int> aux1=aux;
		
		soma+=tracks[i];
		if(soma<=N)
		{
			aux.push(tracks[i]);
			if(soma>maxx)
			{	
				resp=aux;
				maxx=soma;
			}
			
		}
		backtracking(i+1,soma,aux);
		backtracking(i+1,soma-tracks[i],aux1);
	}
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		maxx=0;
		
		scanf("%d",&nt);
		
		for(int i=0;i<nt;i++)
			scanf("%d",&tracks[i]);
		
		queue<int> aux;
		backtracking(0,0,aux);
		
		while(!resp.empty())
		{
			printf("%d ",resp.front());
			resp.pop();
		}
		
		printf("sum:%d\n",maxx);
	}
}



