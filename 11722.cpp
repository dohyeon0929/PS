#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[1001];
ll dp[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        ll MAX = 1;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i]){
                MAX = max(dp[j]+1, MAX);
            }
        }
        dp[i]=MAX;
    }
    // cout<<dp[1]<<'\n';
    cout<<*max_element(dp,dp+n+1);
    return 0;
}