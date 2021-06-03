#include <iostream>
#include <vector>
#include <algorithm>

int n=0;
std::vector<int> num;

typedef unsigned us;

int fun()
{
	int x1=0,x2=0,pr=1,custo=0;
	bool zero=0;
	for(us i=0;i<(us)n;i++)
	{
		if(num[i]==0){
			zero=1;
			custo+=1;
			continue;
		}
		
		x1=std::abs(1-num[i]);
		x2=std::abs(-1-num[i]);
		if(x1<x2){
			pr=pr*1;
			custo+=x1;
		}
		else{
			pr=pr*-1;
			custo+=x2;
		}
	}
	
	if(pr==-1&&!zero){
		custo+=2;
	}
	
	return custo;
}

int main()
{
	scanf("%d",&n);
	num.reserve(n);
	
	int x=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		num.push_back(x);
	}
	
	printf("%d\n",fun());
}
