#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b;
    long double soma=0;
    while(cin>>a&&a!=0&&cin>>b)
    {
        for(unsigned long long i=a+1;i<b;i++)
            if(i%3==0)
                soma+=i;

        cout<<soma<<'\n';
    }
}
