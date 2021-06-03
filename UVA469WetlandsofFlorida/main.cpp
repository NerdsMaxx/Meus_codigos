#include <bits/stdc++.h>

int l=0,c=0;
char mapa[100][100];
int x[8]={0,0,1,-1,1,-1,1,-1};
int y[8]={1,-1,0,0,-1,1,1,-1};

void dfs(int i,int j,int &area)
{
    if(mapa[i][j]=='W')
    {
        mapa[i][j]='V';
        ++area;
        int ni=0,nj=0;
        for(int z=0;z<8;z++)
        {
            ni=i+x[z];
            nj=j+y[z];

            if(ni>=0&&ni<l&&nj>=0&&nj<c)
              dfs(ni,nj,area);
        }
    }
}

int main()
{
    int nt=0;
    scanf("%d ",&nt);
    while(nt--)
    {
        char *a;
        gets(a);
        memset(mapa,0,sizeof mapa);

        while(std::cin>>(mapa[l]+1))
        {
            l++;
        }
        c=std::strlen(mapa[0]);

        int i=0,j=0,area=0;
        while(scanf("%d %d",&i,&j)!=EOF)
        {
            dfs(i,j,area);
            printf("%d\n",area);
            area=0;
        }
        if(nt!=0) printf("\n");
    }
}
