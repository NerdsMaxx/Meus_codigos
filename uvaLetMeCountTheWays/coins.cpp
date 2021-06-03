#include <iostream>

typedef long long ll;

int pd[5][30300];
int v[5]={1,5,10,25,50};

ll fun(int i=0,ll soma=0)
{
	if(i==5)
		return soma==0;
	
	if(soma<0)
		return 0;
		
	if(pd[i][soma]!=-1)
		return pd[i][soma];
		
	ll x=fun(i,soma-v[i]);
	x+=fun(i+1,soma);
	
	return pd[i][soma]=x;
}
