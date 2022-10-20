#define ll long long
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
ll dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n][m];
    return 0;
}