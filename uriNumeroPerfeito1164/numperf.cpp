#include <iostream>
using namespace std;

int main() {
    unsigned int n=0,x=0,div[1000000],pos=0;
    
    scanf("%u",&n);
    for(unsigned int j=0;j<n;j++){
        
        scanf("%u",&x);

        pos=0;
        div[pos]=1;
        ++pos;
        for(unsigned int i=2;i<x;i++){
            bool cond=(x%i==0);
            div[pos]=i*cond;
            pos+=1*cond;
        }
        
        unsigned int soma=0;
        for(unsigned int i=0;i<pos;i++){
            soma+=div[i];
        }

        if(soma==x){
            printf("%u eh perfeito\n",x);
        }
        else{
            printf("%u nao eh perfeito\n",x);
        }

    }
}