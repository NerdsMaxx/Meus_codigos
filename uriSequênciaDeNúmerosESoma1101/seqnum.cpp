#include <bits/stdc++.h>
using namespace std;

int main(){
    int m=0,n=0,soma=0;
       
    while(scanf("%d%d",&m,&n),m>0&&n>0){
        soma=0;

        if(n>m){
            swap(m,n);
        }

        for(int i=n;i<=m;i++){
            printf("%d ",i);
            soma+=i;
        }

        printf("Sum=%d\n",soma);
    }
}