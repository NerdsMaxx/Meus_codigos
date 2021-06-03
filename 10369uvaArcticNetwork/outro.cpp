#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,double> id;
typedef pair<double,ii> dii;

vector<ii> coord;
vector<vector<id>> AdjList;
vector<bool> taken;
vector<vector<bool>> allowed;
priority_queue<dii> pq;

void reset(int n)
{
	coord.clear();
	coord.reserve(n);
	
	AdjList.clear();
	vector<id> aux(0);
	aux.reserve(n);
	AdjList.assign(n,aux);
	
	taken.assign(n,0);
	allowed.assign(n,vector<bool>(n,1));
}

void process(int u)
{
	taken[u]=1;
	
	for(int i=0;i<(int)AdjList[u].size();i++)
	{
		id v=AdjList[u][i];
		
		if(!taken[v.first])
			pq.push(dii(-v.second,ii(-v.first,-u)));
	}
}

void prim(int n)
{
	process(0);
		
	while(!pq.empty())
	{
		dii front=pq.top(); pq.pop();
		int u=-front.second.first, v=-first.second.second; double w=-front.first;
			
		if(!taken[u]) process(u);
		else{ allowed[u][v]=0;
			  allowed[v][u]=0; }
			
		if(pq.empty())
		{
			int i=0;
			for(;i<n&&(AdjList[i].empty()||taken[i]);i++);
			if(i<n)  process(i);
		}
	}
}

double Dminimum(int n)
{
	
}

int main()
{
	int t=0,counter=0; scanf("%d",&t);
	
	while(t--)
	{
		int s,p; scanf("%d%d",&s,&p);
		
		reset(p);

		int x=0,y=0;
		for(int i=0;i<p;i++)
		{
			scanf("%d%d",&x,&y);
			coord.push_back(ii(x,y));
		}
		sort(coord.begin(),coord.end());

		double w=0; ii u,v;
		for(int i=0;i<p;i++)
		{
			u=coord[i];
			for(int j=i+1;j<p;j++)
			{
				v=coord[j];
				w=hypot(u.first-v.first,u.second-v.second);
				AdjList[i].push_back(id(j,w));
				AdjList[j].push_back(id(i,w));
			}
		}
		prim(p);


		
		counter++;
	}
}
