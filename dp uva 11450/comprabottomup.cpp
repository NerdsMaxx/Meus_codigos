#include <bits/stdc++.h>
using namespace std;

int main()
{
	int numdecasos=0;
	cin>>numdecasos;
	for(int t=0;t<numdecasos;t++)
	{
		
		int orcamento, qtdpeca, preco[30][30];
		bool podepagar[30][300];
		memset(podepagar,false,sizeof(podepagar));
		
		
		cin>>orcamento>>qtdpeca;
		for(int i=0;i<qtdpeca;i++)
		{
			cin>>preco[i][0];//qtdmodelos
			for(int j=1;j<=preco[i][0];j++)
			{cin>>preco[i][j];}
		}
		
		int aux=0;
		for(int j=1;j<=preco[0][0];j++)
		{
			
			if((aux=orcamento-preco[0][j])>=0)
			{podepagar[0][aux]=true;}
		}
		
		for(int i=1;i<qtdpeca;i++)
		{
			for(int j=0;j<=orcamento;j++)
			{
				if(podepagar[i-1][j]==true)
				{
					for(int k=1;k<=preco[i][0];k++)
					{
						if((aux=j-preco[i][k])>=0)
						{podepagar[i][aux]=true;}
					}
				}
			}
		}
		
		int i=0;
		for(;i<=orcamento&&podepagar[qtdpeca-1][i]!=true;i++);
		
		if(podepagar[qtdpeca-1][i]!=true){cout<<"no solution\n";}
		else {cout<<orcamento-i<<'\n';}
	
	}
	
}
