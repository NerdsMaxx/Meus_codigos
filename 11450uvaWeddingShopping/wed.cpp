#include <bits/stdc++.h>
using namespace std;

int main()
{
	int g,money,k,tc,m,c;
	int price[25][25];
	bool reachable[25][210];
	
	scanf("%c",&tc);//n casos
	while(tc--)
	{
		scanf("%d%d",&m,&c);//orçamento e vestuario
		for(g=0;g<c;g++)
		{
			scanf("%d",&price[g][0]);//qtd de modelo, vai armaz 'k'
			for(k=1;k<=price[g][0];k++)
				scanf("%d",&price[g][k]);
		}
		
		memset(reachable,false,sizeof reachable);
		for(k=1;k<=price[0][0];k++)
			if(m-price[0][k]>=0)
				reachable[0][m-price[0][k]]=true;
				
		for(g=1;g<c;g++)
		 for(money=0;money<=m;money++)
		  if(reachable[g-1][money])
		   for(k=1;k<=price[g][0];k++)
		    if(money-price[g][k]>=0)
			 reachable[g][money-price[g][k]]=true;
			 
		for(money=0;money<=m&&!reachable[c-1][money];money++)
		
		if(money==m+1) printf("no solution\n");
		else printf("%d\n",m-money);
	}
}
