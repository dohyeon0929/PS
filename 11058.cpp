#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[101][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        for(ll j=i; j<i+3; j++){
            dp[i][j]=max(j, dp[i-1][j]);
        }
        for(ll j=i+3; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][i]*(j-i-1));
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][n];
    return 0;
}