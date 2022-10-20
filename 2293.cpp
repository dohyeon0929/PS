#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[100110]; 
vector<ll> coin;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll now;
    for(int i=0; i<n; i++){
        cin>>now;
        coin.push_back(now);
    }
    for(int x=0; x<n; x++){
        ll coin_now=coin[x];
        dp[coin_now]+=1;
        for(int i=1; i<=k; i++){
            if(i-coin_now>0){
                dp[i]+=dp[i-coin_now];
            }
        }
    }
    cout<<dp[k];

    return 0;
}