#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[501][501];
int dp[501][501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>board[i][j];
            if(board[i-1][j]>board[i][j])dp[i][j]+=dp[i-1][j];
            if(board[i][j-1]>board[i][j])dp[i][j]+=dp[i][j-1];
            if(board[i+1][j]>board[i][j])dp[i+1][j]+=dp[i][j];
            if(board[i][j+1]>board[i][j])dp[i][j]+=dp[i][j+1];
        }
    }
    cout<<dp[n][m];
    return 0;
}