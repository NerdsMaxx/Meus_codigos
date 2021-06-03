#include <bits/stdc++.h>
using namespace std;

int qtddepeca,preco[20][20],memo[25][250];

int compra(int peca, int sobra)
{
	if(sobra<0){
        return 1e9;}
        
	if(peca==qtddepeca){
        return sobra;} 
            
    if(memo[peca][sobra]!=-1){
        return memo[peca][sobra];}

	int sobramin=1e9;
    for(int i:preco[peca]){
		if(i==-1){break;}
        sobramin=min(compra(peca+1,sobra-i),sobramin);}

    memo[peca][sobra]=sobramin;
    return sobramin;
}


int main()
{
	int numdecasos=0;
	scanf("%d",&numdecasos);
	for(int t=0;t<numdecasos;t++)
	{
		memset(memo,-1,sizeof(memo));
		memset(preco,-1,sizeof(preco));
		
		int orcamento=0;
		//printf("Orcamento: ");
		scanf("%d",&orcamento);
		
		//printf("Numeros de peças de roupa: ");
		scanf("%d",&qtddepeca);

		for(int i=0;i<qtddepeca;i++)
		{
			//printf("peca=%d\n",i);
			
			int qtdmodelo;
			//printf("Quantos modelos: ");
			scanf("%d",&qtdmodelo);

			//printf("Colocando preco em cada modelo:\n");
			for(int j=0;j<qtdmodelo;j++)
				scanf("%d",&preco[i][j]);
		}

		int sobra=compra(0,orcamento);
		if(sobra==1e9){printf("no solution\n");}
		else {printf("%d\n",orcamento-sobra);}
	}
}
