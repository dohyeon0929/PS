#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[101];
ll dp[101][21];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    dp[1][arr[1]]=1;
    for(int i=2; i<=n-1; i++){
        for(int j=0; j<=20; j++){
            bool token = false;
            if(dp[i-1][j]!=0){
                if(j-arr[i]>=0) {
                    dp[i][j-arr[i]]+=dp[i-1][j];
                }
                if(j+arr[i]<=20) {
                    dp[i][j+arr[i]]+=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n-1][arr[n]];
    return 0;
}