#include <bits/stdc++.h>
using namespace std;

int main(){
    int cod=0,alc=0,gas=0,dis=0;
       
    while(scanf("%d",&cod),cod!=4){
        
        if(cod<1||cod>5){
            continue;
        }

        alc+= cod==1;
        gas+= cod==2;
        dis+= cod==3;
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",alc);
    printf("Gasolina: %d\n",gas);
    printf("Diesel: %d\n",dis);
}