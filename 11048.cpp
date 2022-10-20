#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0] = arr[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
    }
    cout<<dp[n][m];
    return 0;
}