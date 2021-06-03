#include<bits/stdc++.h>
using namespace std;

int dp[201][201][41], val[201], D, n, m;

int fun(int idn, int idm, int r){
    if (idm == m)
        return r == 0;
    
    if (idn == n)
        return 0;
        
    if (dp[idn][idm][r+20] != -1)
        return dp[idn][idm][r+20];
        
    int v = 0;
    v = fun(idn+1, idm, r);
    v += fun(idn+1, idm+1, (r + val[idn])%D);
    return dp[idn][idm][r+20] = v;
}

int main(){
    int q, cs = 1;
    while(scanf("%d%d", &n, &q), n || q){
        for (int i = 0; i < n; i++){
            scanf("%d", &val[i]);
        }
        printf ("SET %d:\n", cs++);
        for (int i = 0; i < q; i++){
            scanf("%d%d", &D, &m);
            memset(dp, -1, sizeof dp);
            printf ("QUERY %d: %d\n", i+1, fun(0, 0, 0));
        }
    }
}
