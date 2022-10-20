#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=1; i<=n+1; i++){
        dp[i][0]=1;
        for(int j=1; j<=i; j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    } 
    cout<<dp[n-1][k-1];
    return 0;
}