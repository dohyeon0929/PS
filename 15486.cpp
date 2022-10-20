#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[1500002][2];
ll dp[1500002];
vector<pair<ll,ll>> v[1500002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i][0]>>arr[i][1];
        if(i+arr[i][0]<=n+1){
            v[i+arr[i][0]].push_back({i,arr[i][1]});
        }
    }
    for(int i=1;i<=n+1; i++){
        dp[i]=dp[i-1];
        ll mem_dp = dp[i];
        for(auto j : v[i]){
            // cout<<"j.first : "<<j.first<<'\n';
            mem_dp=max(mem_dp,dp[j.first]+j.second);
            // cout<<dp[i]<<'\n'; 
        }
        dp[i]=mem_dp;
        // cout<<"dp[i] : "<<dp[i]<<'\n'<<'\n';
    }
    // for(int i=1; i<=n+1; i++){
    //     cout<<dp[i]<<' ';
    // }
    // cout<<'\n';
    cout<<dp[n+1];
    return 0;
}