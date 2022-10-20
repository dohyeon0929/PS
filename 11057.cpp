#define MOD 10007
#include <bits/stdc++.h>
using namespace std;
int dp[1001][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<=9; i++)dp[1][i]=1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=MOD;
            }
        }
    }
    int ans=0;
    for(int i=0; i<=9; i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}