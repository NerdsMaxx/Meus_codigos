#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0,y=0,resp=0;
    string quadrante[4]={"primeiro","segundo","terceiro","quarto"};

    while(scanf("%d%d",&x,&y),!(x==0||y==0)){
        resp=(x>0&&y>0)*0 + (x<0&&y>0)*1 + (x<0&&y<0)*2 + (x>0&&y<0)*3;
        printf("%s\n",quadrante[resp].c_str());
    }
}

/*A expressão booleano,como por exemplo "x>0&&y>0", retorna 1(true) ou 0(false).
Se for x=3 e y=-2 então a expressão "x>0&&y<0" vai ser verdadeiro, ou seja, 1.
Já o restante das expressões vão ser falsa,ou seja, 0.
Com isso, fica:

    resp=(x>0&&y>0)*0 + (x<0&&y>0)*1 + (x<0&&y<0)*2 + (x>0&&y<0)*3
    resp=         0*0 +          0*1 +          0*2 +          1*3
    resp=3

    quadrante[resp] --> quadrante[3]="quarto"

    Por isso, o programa vai retornar como saída: "quarto"   
*/