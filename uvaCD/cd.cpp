#include <bits/stdc++.h>
using namespace std;

int N=0,nt=0,maxx=0;
int tracks[30];
deque<int> resp,aux;

void backtracking(int i=0,int soma=0)
{
	if(i<nt)
	{	
		soma+=tracks[i];
		if(soma<=N)
		{
			aux.push_back(tracks[i]);
			if(soma>maxx)
			{	
				resp=aux;
				maxx=soma;
			}
			
			backtracking(i+1,soma);
		}
		
		soma-=tracks[i];
		aux.pop_back();
		backtracking(i+1,soma);
	}
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		maxx=0;
		aux.clear();
		
		scanf("%d",&nt);
		
		for(int i=0;i<nt;i++)
			scanf("%d",&tracks[i]);
		
		backtracking();
		
		while(!resp.empty())
		{
			printf("%d ",resp.front());
			resp.pop_back();
		}
		
		
		printf("sum:%d\n",maxx);
	}
}



