#include <bits/stdc++.h>

int nObj=0;
int preco[1001],pesoO[1001];
int pesoP[101];
int pd[1010][30300];

int fun(int i,int pesoD)
{
    if(i>=nObj || pesoD<0)
        return 0;

    if(pd[i][pesoD]!=-1)
        return pd[i][pesoD];

    int max=fun(i+1,pesoD);
    if(pesoD>=pesoO[i])
        max=std::max(fun(i+1,pesoD-pesoO[i])+preco[i],max);

    return pd[i][pesoD]=max;
}

int main()
{
    int nTest=0;
    scanf("%d",&nTest);
    for (int i=0;i<nTest; i++)
    {
        memset(pd,-1,sizeof pd);

        scanf("%d",&nObj);
        for (int j=0;j<nObj;j++)
            scanf("%d %d",&preco[j],&pesoO[j]);

        int nPss=0;
        scanf("%d",&nPss);
        for (int z=0;z<nPss;z++)
            scanf("%d",&pesoP[z]);

        int valorMax=0;
        for (int q=0;q<nPss;q++)
        valorMax+=fun(0,pesoP[q]);

        printf("%d\n",valorMax);
    }
}
