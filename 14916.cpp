#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    fill(dp, dp+n+1, INF);
    dp[2]=1; dp[4]=2;dp[5]=1;
    for(int i=6; i<=n; i++){
        dp[i] = min(dp[i], dp[i-2]+1);
        dp[i] = min(dp[i], dp[i-5]+1);
    }
    if(dp[n]==INF)cout<<-1;
    else cout<<dp[n];
    return 0;
}