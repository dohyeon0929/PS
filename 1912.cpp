#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int dp[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    
    int ans = arr[0];
    dp[0]=arr[0];
    for(int i=1; i<n; i++){
        dp[i]=max(dp[i-1]+arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}