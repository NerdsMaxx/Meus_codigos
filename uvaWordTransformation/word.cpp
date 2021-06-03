#include <iostream>
#include <string>
#include <vector>
#include <map>

#define us unsigned
#define str std::string

int LIMdic=0;
str dic[250];
std::map<str,std::vector<str>> viz;
std::map<str,bool> undir;
std::map<str,int> dist;

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

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
	
	return unico==true;
}

int bfs(str &origem){
	
	for(int i=0;i<LIMdic;i++){
		dist[dic[i]]=1e9;
		undir[dic[i]]=false;
	}
	
	std::queue<str> fila;
	fila.push(origem);
	dist[origem]=0;
	undir[origem]=true;
	
	while(!fila.empty()){
		str p=fila.front();
		fila.pop();
		
		for(int i=0;i<LIMdic;i++){
			if(undir[dic[i]]!=true){
				if(vfc(p,dic[i])){
					viz[p].push_back(dic[i]);
					undir[dic[i]]=true;
				}
			}
		}
		
		us lim=viz[p].size();
		str x="";
		for(us i=0;i<lim;i++){
			x=viz[p][i];
			if(dist[p]+1<dist[x]){
				dist[x]=dist[p]+1;
				fila.push(x);
			}
		}
	}
}

int main(){
	int N=0;
	char ch[5];
	scanf("%d",&N);
	std::cin.getline(ch,5);
	std::cin.ignore();
	
	for(int i=0,i<N;i++){
		str plv="";
		int cont=0;
		while(std::cin>>plv&&plv!="*"){
			dic[cont]=plv;
			cont++;
		}
		LIMdic=cont;
		plv="";
		std::cin.ignore();
		while(std::getline(std::cin,plv)&&plv!=""){
			std::vector<str> x=split(plv,' ');
			bfs(x[0]);
			printf("%s %s %d",x[0].c_str(),x[1].c_str,dist[x[1]]);
		}
	}
}
