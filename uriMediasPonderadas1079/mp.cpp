#include <bits/stdc++.h>
using namespace std;

int main(){
    int ndecasos=0;
    float v[3];//vetor
    scanf("%d",&ndecasos);
    
    for(int i=0;i<ndecasos;i++){

        for(int j=0;j<3;j++){
            scanf("%f",&v[j]);
        }

        float media_ponderada=(v[0]*2+v[1]*3+v[2]*5)/10;
        printf("%.1f\n",media_ponderada);
    }
}