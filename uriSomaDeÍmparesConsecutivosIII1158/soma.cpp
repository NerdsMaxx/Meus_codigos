#include <iostream>
using namespace std;

int main() {
    int n=0,x=0,y=0,soma=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        soma=0;

        scanf("%d%d",&x,&y);
        x=x+1*(x%2==0);

        for(int j=0;j<y;j++){
            soma+=x;
            x+=2;
        }
        printf("%d\n",soma);
    }
}