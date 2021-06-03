#include <iostream>
#include <algorithm>

int pd[1005][1005];
std::string p;

void inc()
{
	int lim=(int)p.size();
	for(int i=0;i<lim;i++)
		for(int j=0;j<lim;j++)
			pd[i][j]=-1;
}

int fun(int i=0,int f=p.size()-1,int lg=0)
{	
	int result=0;
	
	if(i>f){
		return 0;
	}
	else if(pd[i][f]!=-1){
		return pd[i][f];
	}
	else if(p[i]==p[f]&&i!=f){
		result=2+fun(i+1,f-1,lg+2);
	}
	else if(p[i]==p[f]){
		return 1;
	}
	else if(i==f){
		return 0;
	}
	else{
	int tmp1=fun(i,f-1,lg);
	int tmp2=fun(i+1,f,lg);
	result=std::max(tmp1,tmp2);
	}
	
	return pd[i][f]=result;
}

int main()
{
	int t=0;
	scanf("%d",&t);
	
	std::cin.ignore();
	while(t--)
	{
		std::getline(std::cin,p);	
		
		int r=0;
		if(!p.empty()) 
		{inc();
		r=fun();}
			
		printf("%d\n",r);
	}
}
