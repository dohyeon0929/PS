#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[41];
ll vip[41];
ll dp[41];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>vip[i];
    }
    vip[m+1]=n+1;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=40; i++){
        if(i%2==0){
            dp[i]=dp[i/2]*dp[i/2];
            dp[i]+=dp[i/2-1]*dp[i/2-1];
        }
        else{
            dp[i]=dp[i/2]*dp[i/2+1];
            dp[i]+=dp[i/2-1]*dp[i/2];
        }
    }
    ll ans=1;
    // for(int i=0; i<=10; i++){
    //     cout<<dp[i]<<' ';
    // }
    // cout<<'\n';
    for(int i=1; i<=m+1; i++){

        ans*=dp[vip[i]-vip[i-1]-1];
        // cout<<ans<<'\n';
    }
    cout<<ans; 
    return 0;
}