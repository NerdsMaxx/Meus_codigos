#include <bits/stdc++.h>
using namespace std;

int n,ant,prox,minn;

int main()
{
	scanf("%d",&n);
	scanf("%d",&ant);
	minn=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&prox);
		if(ant+prox<0)
		{
			minn+=abs(ant+prox);
			ant=0;
		}
		else ant=ant+prox;
	}
	
	printf("%d\n",minn);
}
