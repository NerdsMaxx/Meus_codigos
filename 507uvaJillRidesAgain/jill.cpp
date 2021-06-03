#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,arr[50000];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		n--;
		for(int j=0;j<n;j++)
			scanf("%d",&arr[j]);
			
		int sum=0,ans=arr[0],fp=0;	
		for(int j=0;j<n;j++)
		{
			sum+=arr[j];
			ans=max(ans,sum);
			if(ans==sum) fp=j;
			if(sum<0) sum=0;
			arr[j]=sum;
		}
		
		int ip=fp;
		for(;ip>=0&&arr[ip]!=0;ip--);
		ip++;
		
		if(ans<0) printf("Route %d has no nice parts\n",i+1);
		else printf("The nicest part of route %d is between stops %d and %d\n",i+1,ip+1,fp+2);
	}
}
