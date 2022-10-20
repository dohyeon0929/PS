#define INF 123456789
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[100110]; 
set<ll> used_coin;
vector<ll> coin;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll now;
    fill(dp, dp+100110, INF);
    for(int i=0; i<n; i++){
        cin>>now;
        coin.push_back(now);
    }
    for(int x=0; x<n; x++){
        if(used_coin.find(coin[x])!=used_coin.end())continue;
        ll coin_now=coin[x];
        used_coin.insert(coin[x]);
        dp[coin_now]=1;
        for(int i=1; i<=k; i++){
            if(i-coin_now>0){
                dp[i]=min(dp[i-coin_now]+1, dp[i]);
            }
        }
    }
    // for(int i=1; i<=k; i++){
    //     cout<<dp[i]<<' ';
    // }
    // cout<<'\n';
    if(dp[k]==123456789)cout<<-1;
    else cout<<dp[k];

    return 0;
}