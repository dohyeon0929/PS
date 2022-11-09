#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int dp[100001][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];        
    }
    dp[0][0]=arr[0];
    dp[0][1]=0; 
    int ans = dp[0][0];
    for(int i=1; i<n; i++){
        dp[i][0] = ( dp[i-1][0]<0 ? arr[i] : dp[i-1][0] + arr[i]);
        dp[i][1] = (dp[i-1][1]<0 ? 0 : max(dp[i-1][0], dp[i-1][1]+arr[i]));
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    bool flag = true;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            flag= false;
            break;
        }
    }
    if(flag){
        ans = *max_element(arr, arr+n);
    }
    cout<<ans;
    return 0;
}