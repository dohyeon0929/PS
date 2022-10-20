#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(int i=3; i<=n; i++){
        if(i%2==0){
            dp[i] = dp[i/2] * dp[i/2];
            dp[i]+= dp[i/2-1] * dp[i/2-1] * 2;
        }
        else{
            dp[i] = dp[i/2] * dp[i/2+1];
            dp[i] += dp[i/2-1]*dp[i/2]*2;
        }
        dp[i] %= 10007;
    }
    cout<<dp[n];
    return 0;
}