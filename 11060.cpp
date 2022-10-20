#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    fill(dp, dp+n+1, INF);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=arr[i]; j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    // for(int i=0; i<n; i++)cout<<dp[i]<<' ';
    // cout<<'\n';
    if(dp[n-1]==INF)cout<<-1;
    else cout<<dp[n-1];
    return 0;
}