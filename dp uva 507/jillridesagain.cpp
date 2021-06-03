#include<bits/stdc++.h>
using namespace std;

pair<int,int> somaMax(int a[],int tam)
{
    int max_ate_agora=-1,max_atual=0,
    comeco=0,fim=0,s=0;

    for(int i=0;i<tam;i++)
    {
        max_atual+=a[i];

        if(max_atual<0)
        {max_atual=0;
         s=i+1;}

        else if(max_atual>max_ate_agora)
        {max_ate_agora=max_atual;
         comeco=s;
         fim=i+1;}

        else if(max_atual==max_ate_agora)
        {
            if(i+1-s>fim-comeco)
            {comeco=s;
             fim=i+1;}
        }
    }

    return make_pair(comeco+1,fim+1);
}


int main()
{
    int numrotas=0;
    scanf("%d",&numrotas);
    for(int i=0;i<numrotas;i++)
    {
        int numparadas=0;
        scanf("%d",&numparadas);

        int a[numparadas];
        for(int j=0;j<numparadas-1;j++)
        {scanf("%d",&a[j]);}

        pair<int,int> resp=somaMax(a,numparadas-1);

        if(resp.second==1) {printf("Route %d has no nice parts\n",i+1);}
        else {printf("The nicest part of route %d is between stops %d and %d\n",i+1,resp.first,resp.second);}
    }
}
