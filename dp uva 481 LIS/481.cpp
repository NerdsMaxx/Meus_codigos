#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int main()
{
	int A[MAXN],num=0,i=0;
	while(scanf("%d",&num)!=EOF)
	{
		A[i]=num;
		i++;
	}
	int tam=i;
	
	int L[MAXN],L_id[MAXN],P[MAXN],lis=0,lis_end=0,pos=0;
	for(i=0;i<tam;i++)
	{
		pos=lower_bound(L,L+lis,A[i])-L;
		L[pos]=A[i];
		L_id[pos]=i;
		
		P[i]=pos ? L_id[pos-1] : -1;
		
		if(pos+1>lis)
		{
			lis=pos+1;
			lis_end=i;
		}
		else if(pos==lis-1)
		{lis_end=i;}
	}
	
	printf("%d\n-\n",lis);
	
    i=lis_end;
	stack<int> s;
	
	for (; P[i] >= 0; i=P[i])
	{s.push(A[i]);}
	
	printf("%d\n",A[i]);
	
	for (;!s.empty();s.pop())
	{printf("%d\n", s.top());}
} 
