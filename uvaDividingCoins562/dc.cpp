#include <iostream>
#include <cmath>

int m,metade;
int pd[110][50500];
int valor[110];

int funcao(int i=0,soma=0)
{
	if(i==n)
		return 0;
	
	if(pd[i][soma]!=-1)
		return pd[i][soma];
		
	int soma1=0;	
	if(metade-soma>=valor[i])
		soma1=valor[i]+funcao(i+1,soma+valor[i]);
		
	soma1=std::max(soma1,funcao(i+1,soma));
	
	return pd[i][soma]=soma1;
}
