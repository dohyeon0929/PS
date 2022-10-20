#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[101][10001];
ll arr1[101];
ll arr2[101];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr1[i];
    }
    for(int i=1; i<=n; i++){
        cin>>arr2[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=10000; j++){
            if(j-arr2[i]>=0)
                dp[i][j]=max(dp[i][j],arr1[i]+dp[i-1][j-arr2[i]]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    for(int i=0; i<=10000; i++){
        if(dp[n][i]>=m){
            cout<<i;
            break;
        }
    }
    return 0;
}