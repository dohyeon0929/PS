#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[65][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    for(int i=0; i<=9; i++)dp[1][i]=1;
    for(int i=2; i<=64; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        ll ans=0;
        for(int j=0; j<=9; j++){
            ans+=dp[n][j];
        }
        cout<<ans<<'\n';
    }
    return 0;
}