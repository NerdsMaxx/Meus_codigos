#include <bits/stdc++.h>
using namespace std;
typedef unsigned us;

vector<string> dic;
dic.reserve(300);

vector<string> viz[300];
map<string,bool> vis;
map<string,int> dist;
map<string,int> parada;

bool vfc(str &a,str &b){
	if(a.size()!=b.size()||a==b){
		return false;
	}
	
	us lim=a.size();
	bool unico=false;
	for(us i=0;i<lim;i++){
		if(a[i]!=b[i]){
			if(unico==true){
				return false;
			}
			unico=true;
		}
	}
	return true;
}

void bfs(string &origem)
{
	queue<string> fila;
	fila.push(origem);
	
	while(!fila.empty())
	{
		string x=fila.front();
		fila.pop();
		
		vis.insert(i);
		
		for(string &i:dic)
		{
			if(vfc(x,i))
			{
				viz[x].push_back(i);
				
				if(!vis[i])
					fila.push(i);
					
				parada
			}
		}
	}
}

int main()
{
	
}
