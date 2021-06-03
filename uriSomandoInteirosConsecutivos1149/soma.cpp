#include <bits/stdc++.h>
using namespace std;

int main(){
    int A=0,N=0,soma=0;
    
    scanf("%d",&A);
    
    while(scanf("%d",&N),N<=0);

    for(int i=0;i<N;i++){
        soma+=A+i;
    }

    printf("%d\n",soma);
}