#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll board[101][101];
ll dp[101][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll now;
    dp[0][0]=1;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>now;
            board[i][j]=now;
            if(i==n-1&&j==n-1)break;
            if(i+now<n)
                dp[i+now][j]+=dp[i][j];
            if(j+now<n)
                dp[i][j+now]+=dp[i][j];
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n-1][n-1];

    return 0;
}