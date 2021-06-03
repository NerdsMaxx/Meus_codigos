#include <bits/stdc++.h>
using namespace std;

int main(){
    float S=0;
    for(float x=1,y=1;x<=39;x+=2,y*=2){
        S+=x/y;
    }

    printf("%.2f\n",S);
}