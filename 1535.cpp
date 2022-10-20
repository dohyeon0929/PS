#include <bits/stdc++.h>
using namespace std;
int hp[21], happy[21], dp[21][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>hp[i];
    }
    for(int i=1; i<=n; i++){
        cin>>happy[i];
    }
    for(int i=1; i<=n; i++){
        dp[i][hp[i]]=max(dp[i][hp[i]],happy[i]);
        for(int j=0; j<=99; j++){
            if(j+hp[i]<=99) dp[i][j+hp[i]]=max(dp[i-1][j+hp[i]], dp[i-1][j]+happy[i]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j!=0) dp[i][j]=max(dp[i][j], dp[i][j-1]);
        }
    }

    int ans=0;
    for(int i=0; i<=99; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans;
    return 0;
}