#include <bits/stdc++.h>
using namespace std;

int LIS(int *arr, int &n,bool smaller,int i=0, int prev=INT_MIN, int lis_n=0){
    if(i==n){
        return lis_n;
    }

    int inc=INT_MIN;
    if(smaller&&prev<arr[i]){
        inc=LIS(arr,n,!smaller,i+1,arr[i],lis_n+1);
    }
    else if(!smaller&&prev>arr[i]){
        inc=LIS(arr,n,smaller,i+1,arr[i],lis_n+1);
    }

    int exc=LIS(arr,n,i+1,prev,lis_n);

    return max(inc,exc);
}
