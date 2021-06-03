#include <bits/stdc++.h>
using namespace std;

int nv=0,na=0;
vector<int> viz[101];
bool nvis[101];
vector<int> rsp;//respostas



void dfs(int i)
{
    if(nvis[i])
    {
        rsp.push_back(i);
        for(unsigned j=0;j<viz[i].size();j++)
            dfs(viz[i][j]);
    }
}

int main()
{
    scanf("%d %d",&nv,&na);
    rsp.reserve(nv);
    int i=na,a=0,b=0;
    while(i--)
    {
        scanf("%d %d",&a,&b);
        viz[b].push_back(a);
    }Wetlands of Florida
}
