#include <bits/stdc++.h>
using namespace std;

#define f first;
#define s second;
typedef pair<int,int> ii;
int M=0,N=0;
bool m[100][100];
int B1=0,B2=0,E1=0,E2=0;
std::string orientation;

int dist[100][100];
int x[12]={3,-3,0,0,2,-2,0,0,1,-1,0,0};
int y[12]={0,0,3,-3,0,0,2,-2,0,0,1,-1};


void bfs()
{
	char current;
	current=orientation[0];
	queue<ii> q;
	q.push(make_pair(B1,B2));
	dist[B1][B2]=0;
	
	while(!q.empty())
	{
		ii v=q.front();
		q.pop();
		
		for(int i=0;i<12;i++)
		{
			ii n=make_pair(v.f+x[i],v.s+y[i]);
			
			if(n.f<=0||n.f>=M-1||n.s<=0||n.s>=N-1)
				continue;
				
			if(dist[v.f][v.s]+1<dist[n.f][n.s])
			{
				dist[n.f][n.s]=dist[v.f][v.s]+1;
				q.push(n);
				vis.insert(n);
			}
		}
	}
}


int main()
{
	scanf("%d%d,&M,&N");
	while(M!=0||N!=0)
	{
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				m[i][j]=0;
		
		bool aux=0;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&aux);
				if(aux==1)
				{
					m[i][j]=1;
					m[i][j+1]=1;
					m[i+1][j]=1;
					m[i+1][j+1]=1;
				}
			}
		}
			
				
		scanf("%d%d%d%d",&B1,&B2,&E1,&E2);
		cin>>orientation;
	}
}


int M=0,N=0;
bool m[100][100];
int B1=0,B2=0,E1=0,E2=0;
std::string orientation;

int time[100][100];
int x[12]={3,-3,0,0,2,-2,0,0,1,-1,0,0};
int y[12]={0,0,3,-3,0,0,2,-2,0,0,1,-1};


void bfs()
{
	char current;
	current=orientation[0];
	queue<ii> q;
	q.push(make_pair(B1,B2));
	dist[B1][B2]=0;
	
	while(!q.empty())
	{
		ii v=q.front();
		q.pop();
		
		for(int i=0;i<12;i++)
		{
			ii n=make_pair(v.f+x[i].f,v.s+y[i]);
			char nort=x[i].s;
			
			if(n.f<=0||n.f>=M-1||n.s<=0||n.s>=N-1)
				continue;
				
			int t=0;
			
			if(current!=nort)
				fun(current,nort,t);	
				
			if(time[v.f][v.s]+t+1<time[n.f][n.s])
			{
				
				time[n.f][n.s]=time[v.f][v.s]+1+t;
				q.push(n);
			}
		}
	}
}


int main()
{
	scanf("%d%d,&M,&N");
	while(M!=0||N!=0)
	{
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				m[i][j]=0;
		
		bool aux=0;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&aux);
				if(aux==1)
				{
					m[i][j]=1;
					m[i][j+1]=1;
					m[i+1][j]=1;
					m[i+1][j+1]=1;
				}
			}
		}
			
				
		scanf("%d%d%d%d",&B1,&B2,&E1,&E2);
		cin>>orientation;
	}
}



void fun(char &o,char &d,int &t)
{
	char aux=o;
	for(int i=0;i<4;i++)
	{
		if(compass[i]==aux)
		{
			++t;
		
			if(i+1==4)
				i==-1;
		
			aux=compass[i+1];
			if(aux==d)
				break;
		}
	}
}
