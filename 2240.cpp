#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1002][32][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,w;
    cin>>t>>w;
    for(int i=1; i<=t; i++){
        cin>>arr[i];
    }
    if(arr[1]==1)dp[1][0][1]=1;
    else dp[1][1][2]=1;
    for(int i=2; i<=t; i++){
        for(int j=0; j<=w; j++){
            if(j==0){
                dp[i][0][1]=dp[i-1][0][1];
                dp[i][0][2]=dp[i-1][0][2];
            }
            else{
                dp[i][j][1]=max(dp[i-1][j][1], dp[i-1][j-1][2]);
                dp[i][j][2]=max(dp[i-1][j][2], dp[i-1][j-1][1]);
            }
            dp[i][j][arr[i]]++;
        }
    }
    int ans = 0;
    for(int i=0; i<=w; i++){
        for(int j=1; j<=2; j++){
            ans = max(ans, dp[t][i][j]);
        }
    }
    cout<<ans;
    return 0;
}