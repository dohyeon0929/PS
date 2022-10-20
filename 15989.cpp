#include <bits/stdc++.h>
using namespace std;
int dp[10001][4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    for(int i=1; i<=3; i++)dp[i][i]=1;
    for(int i=0; i<=10000; i++){
        for(int j=1; j<=3; j++){
            for(int k=j; k<=3; k++){
                dp[i+j][j]+=dp[i][k];
            }
        }
    }
    for(int i=0; i<t; i++){
        cin>>n;
        int ans=0;
        for(int i=1; i<=3; i++){
            ans += dp[n][i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}