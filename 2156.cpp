#include <bits/stdc++.h>
using namespace std;
int n, arr[10001] , dp[10001][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    dp[0][1]=arr[0];
    for(int i=1; i<n; i++){
        dp[i][0]=max(dp[i-1][1], dp[i-1][2]);
        dp[i][0]=max(dp[i-1][0], dp[i][0]);
        dp[i][1]=dp[i-1][0]+arr[i];
        dp[i][2]=dp[i-1][1]+arr[i];
    } 
    cout<<*max_element(dp[n-1], dp[n-1]+3);
    return 0;
}