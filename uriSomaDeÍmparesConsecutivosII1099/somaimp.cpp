#include <bits/stdc++.h>
using namespace std;

int main(){
    int ndecasos=0,x=0,y=0,soma=0;
    scanf("%d",&ndecasos);
    
    for(int i=0;i<ndecasos;i++){
        soma=0;

        scanf("%d%d",&x,&y);
        if(x>y){
            swap(x,y);
        }

        for(int i=x+1;i<y;i++){
            if(i%2){
                soma+=i;
            }
        }

        printf("%d\n",soma);
    }
}