#include <bits/stdc++.h>
using namespace std;

int n,q,l,r,v,a1,a2;
int arr[60000000];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&l,&r,&v);
		for(int j=l-1;j<r;j++)
			arr[j]+=v;
			
		a1=arr[0];
		for(int j=1;j<n;j++)
		{
			a2=arr[j];
			a1=a2-a1;
		}
		printf("%d\n",a1);
	}
}
