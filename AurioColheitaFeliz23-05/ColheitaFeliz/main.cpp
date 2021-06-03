#include <bits/stdc++.h>
using namespace std;

int n,m,xc,yc,lim;
char mat[100][100];
int dist[100][100];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};


int BFS(int ox,int oy)
{
    queue<pair<int,int>> fila;
    dist[ox][oy]=0;
    fila.push(make_pair(ox,oy));
    while(!fila.empty())
    {
        pair<int,int> u=fila.front(); fila.pop();
        for(int i=0;i<4;i++)
        {
            int xi=u.first+xx[i]; int yi=u.second+yy[i];

            if(xi<0||xi>=n||yi<0||yi>=m)
                continue;

            if(mat[xi][yi]=='O')
                continue;

            if(dist[u.first][u.second]+1<dist[xi][yi])
            {
                dist[xi][yi]=dist[u.first][u.second]+1;
                fila.push(make_pair(xi,yi));
            }

            if(mat[xi][yi]=='C')
                lim--;

            if(!lim)
              return dist[xc][yc];
        }
    }
    return dist[xc][yc];
}


int main()
{
    while(cin>>n>>m&&(n!=0||m!=0))
    {
        int x,y;
        cin>>x>>y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='C')
                {
                    xc=i,yc=j;
                }
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dist[i][j]=1e9;

        lim=(xc<n-1) + (yc<m-1) + (xc>0) + (yc>0);

        cout<<BFS(x,y)<<'\n';
    }
}
