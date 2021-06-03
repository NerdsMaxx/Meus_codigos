#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1
bool dfs_num[30];
map<string,int> id;
map<int,string> str;
vector<int> adj_list[30];
vector<int> adj_list_t[30];
vector<int> S;
 
void reset(int &n)
{
	memset(dfs_num,UNVISITED,sizeof(dfs_num));
	
	vector<int> c(0);
	for(int i=0;i<n;i++)
	{
		adj_list[i].swap(c);
		adj_list_t[i].swap(c);
		
		adj_list[i].reserve(n);
		adj_list_t[i].reserve(n);
	}
	S.swap(c);
	S.reserve(n);
	
	id.clear();
	str.clear();
}

void kosaraju(int &u,bool pass)
{
	dfs_num[u]=VISITED;
	vector<int> neighbor;
	if(pass==0) neighbor=adj_list[u];
	else neighbor=adj_list_t[u];
	
	for(int &v:neighbor)
		if(dfs_num[v]==UNVISITED)
			kosaraju(v,pass);
			
	S.push_back(u);
}

void add_idtostr(string &u,int &c)
{
	if(id.find(u)==id.end())
	{
		id[u]=c;
		str[c]=u;
		c++;
	}
}

int main()
{
	int n=0,m=0,counter_set=1;
	//bool first=true;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		//if(!first)
			//printf("\n");
		
		//first=false;
		
		reset(n);
		
		string u="",v="";
		int c=0;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			add_idtostr(u,c);
			add_idtostr(v,c);
			adj_list[id[u]].push_back(id[v]);
			adj_list_t[id[v]].push_back(id[u]);
		}
		
		for(int i=0;i<n;i++)
			if(dfs_num[i]==UNVISITED)
				kosaraju(i,0);
				
				
		memset(dfs_num,UNVISITED,sizeof(dfs_num));
		printf("Calling circles for data set %d:\n",counter_set);
		for(int i=n-1;i>=0;i--)
		{
			if(dfs_num[S[i]]==UNVISITED)
			{
				kosaraju(S[i],1);
				
				int lim=(int)S.size()-1;
				
				for(int j=n;j<lim;j++)
					printf("%s, ",str[S[j]].c_str());
				
				printf("%s\n",str[S[lim]].c_str());
				
				n=lim+1;
			}
		}
			
		
		
		/*int x=0,xtam=0;
		for(int i=0;i<n;i++) 1
		{
			if(comp[i]==x)
			{
				if(xtam==tam[x]-1)
					printf("%s\n",str[i].c_str());
				else 
					printf("%s, ",str[i].c_str());
				
				++xtam;
			}
			
			if(i==n-1&&x!=SCC)
			{
				xtam=0;
				++x;
				i=-1;
			}
		}*/
		
		
		/*for(int i=0;i<SCC;i++) 2
		{
			int lim=(int)comp[i].size();
			for(int j=0;j<lim-1;j++)
				printf("%s, ",comp[i][j].c_str());
				
			printf("%s\n",comp[i][lim-1].c_str());
		}*/
		
		printf("\n");
	}
}
