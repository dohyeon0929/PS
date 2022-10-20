#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        if(i%2==0){
            dp[i]=dp[i/2]*dp[i/2];
            dp[i]+=dp[i/2-1]*dp[i/2-1];
        }
        else{
            dp[i]=dp[i/2]*dp[i/2+1];
            dp[i]+=dp[i/2-1]*dp[i/2];
        }
        dp[i]%=15746;
    }
    cout<<dp[n]%15746;
    return 0;
}