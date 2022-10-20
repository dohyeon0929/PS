#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[126];
int dp[300001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    arr[1]=1;
    for(int i=2; i<=125; i++){
        arr[i]=arr[i-1]+(i*(i+1))/2;
    }
    fill(dp, dp+300001, INF);
    dp[0]=0;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=125; j++){
            if(i+arr[j]>n)break;
            dp[i+arr[j]]=min(dp[i+arr[j]],dp[i]+1);
        }
    }
    cout<<dp[n];
    return 0;
}