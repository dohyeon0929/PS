#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
int dp[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2]+1;
        dp[i]%=MOD;
    } 
    cout<<dp[n];
    return 0;
}