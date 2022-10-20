#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[36];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    dp[0]=1;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<i; j++){
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }
    cout<<dp[n];
    return 0;
}