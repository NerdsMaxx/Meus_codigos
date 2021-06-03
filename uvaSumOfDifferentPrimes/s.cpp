#include <iostream>
#include <vector>

bool pd[200];
int n=0,k=0;
unsigned int qtd=0;
std::vector<int> primo;

void crivo(){
	
  bool e_composto[1126];

  primo.reserve(200);

  for(int i=0; i<=1125;i++){
	e_composto[i]=0;
  }
	
  e_composto[1] = 1;
  
  for(unsigned int i = 2; i<=1125; ++i){
    if(!e_composto[i]){
      for(unsigned int j = 2; j*i<=1125; ++j){
        e_composto[j*i]=1;
	  }
	  primo.push_back(i);
	}
  }
}

bool fun(int idk=k,int i=0,int subs=n)
{
	if(idk==0){
		qtd+= (subs==0);
		return true;
	}
	
	if(subs-primo[i]<0){
		return false;
	}
	
	if(pd[i]==false){
	 pd[i]=fun(idk-1,i+1,subs-primo[i]);
	}	
	fun(idk,i+1,subs);

	return pd[i];
}

int main()
{
	crivo();
	while(scanf("%d %d",&n,&k)&&(n!=0||k!=0))
	{
		for(int i=0;primo[i]<=n;i++){
			pd[i]=false;
		}
		
		qtd=0;	
		fun();
		printf("%u\n",qtd);
	}
}
