#include <bits/stdc++.h>
using namespace std;
int board[100001][3];

int dp[2][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>board[i][j];
        }
    }
    dp[0][0]=board[0][0];
    dp[0][1]=board[0][1];
    dp[0][2]=board[0][2];
    int i=1;
    for(int x=1; x<n; x++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+board[x][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=max(dp[i-1][2],dp[i][1])+board[x][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][2])+board[x][2];

        for(int j=0; j<3; j++){
            dp[0][j]=dp[1][j];
        }
    }
    cout<<*(max_element(dp[0], dp[0]+3))<<' ';
    dp[0][0]=board[0][0];
    dp[0][1]=board[0][1];
    dp[0][2]=board[0][2];
    
    for(int x=1; x<n; x++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+board[x][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=min(dp[i-1][2],dp[i][1])+board[x][1];
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+board[x][2];

        for(int j=0; j<3; j++){
            dp[0][j]=dp[1][j];
        }
 
    }
    cout<<*(min_element(dp[0], dp[0]+3));
    

    return 0;
}