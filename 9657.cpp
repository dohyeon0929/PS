#include <bits/stdc++.h>
using namespace std;
bool dp[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[1]=dp[3]=dp[4]=1;
    cout<<"1 0 1 1 ";
    for(int i=5; i<=15; i++){
        dp[i] |= !dp[i-1];
        dp[i] |= !dp[i-3];
        dp[i] |= !dp[i-4];
        cout<<dp[i]<<' ';
    }
    if(dp[n])cout<<"SK";
    else cout<<"CY";
    return 0;
}