#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0,z=0,soma=0,cont=0;
    
    scanf("%d",&x);
    
    while(scanf("%d",&z),z<=x);

    while(soma<=z){
        soma+=x,++x,++cont;
    }

    printf("%d\n",cont);
}