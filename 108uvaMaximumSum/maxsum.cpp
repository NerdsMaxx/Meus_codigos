#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n=0,arr[1000][1000];
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		scanf("%d",&arr[i][j]);
		if(i>0) arr[i][j]+=arr[i-1][j];
		if(j>0) arr[i][j]+=arr[i][j-1];
		if(i>0&&j>0) arr[i][j]-=arr[i-1][j-1];
	}
			
	int maxSubRect=-127*100*100,subRect=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=i;k<n;k++)
	for(int l=j;l<n;l++)
	{
		subRect=arr[k][l];
		if(i>0) subRect-=arr[i-1][l];
		if(j>0) subRect-=arr[k][j-1];
		if(i>0&&j>0) subRect+=arr[i-1][j-1];
		maxSubRect=max(maxSubRect,subRect);
	}
	
	printf("%d\n",maxSubRect);
}
