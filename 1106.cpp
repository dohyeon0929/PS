#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[101];
int dp[2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n;
    cin>>c>>n;
    int a,b;
    fill(arr, arr+101, INF);
    fill(dp, dp+2001, INF);
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr[b]=min(arr[b], a);
    }
    dp[0]=0;
    for(int i=0; i<=c; i++){
        for(int j=1; j<=100; j++){
            if(arr[j]!=0){
                dp[i+j]=min(dp[i+j], dp[i]+arr[j]);
            }
        }
    }
    int ans= INF;
    for(int i=2000; i>=c; i--){
        ans = min(ans, dp[i]);
    }
    cout<<ans;

    return 0;
}