#include <iostream>

int pd[15][500];
double v[11]={100,50,20,10,5,2,1,0.5,0.2,0.1,0.05};
double vfinal=0.0;

int fun(int i=0,double soma=0.0)
{
	if(soma>vfinal)
		return 0;
	
	if(i==11)
		return soma==vfinal;
	
	if(pd[i][soma]!=-1)
		return pd[i][soma];
	
	int x=fun(i,soma+v[i]);
	x+=fun(i+1,soma);
	
	return pd[i][soma]=x;
}

int main()
{
	while(scanf("%lf",&vfinal)&&vfinal!=0.00)
	{
		printf("%lf\n",)
	}
}

