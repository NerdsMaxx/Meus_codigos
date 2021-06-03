#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,arr[10000];
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		int ans=arr[0],sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=arr[i];
			ans=max(ans,sum);
		
			if(sum<0) sum=0;
		}
		
		if(ans>0) cout<<"The maximum winning streak is "<<ans<<'.'<<endl;
		else cout<<"Losing streak."<<endl; 
	}
}
