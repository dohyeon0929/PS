#include <bits/stdc++.h>
using namespace std;
int arr[201];
int dp[201];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i]=1;
    }
    int ans=0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[j]+1, dp[i]);
                ans=max(ans,dp[i]);
            }
        }
    } 
    cout<<n-ans;
    return 0;
}