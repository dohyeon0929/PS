#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    fill(dp, dp+1001, INF);
    dp[0]=0;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i+j>n)break;
            dp[i+j]=min(dp[i+j],dp[i]+arr[j]);
        }
    }
    cout<<dp[n];
    return 0;
}