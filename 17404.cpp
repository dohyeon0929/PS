#include <bits/stdc++.h>
using namespace std;
int board[1001][3];
int dp[1001][3];
int dp_start_color[1001][3];
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
    for(int i=0; i<3; i++){
        dp[0][i]=board[0][i];
        dp_start_color[0][i]=i;
    }
    int ans = 123456789;
    for(int t=0; t<3; t++){
        for(int i=0; i<3; i++){
            if(t!=i)
                dp[1][i]=board[1][i]+dp[0][t];
            else
                dp[1][t]=123456789;
        }
        for(int i=2; i<n; i++){
            for(int j=0; j<3; j++){
                dp[i][j]=board[i][j];
                if(dp[i-1][(j+1)%3]<dp[i-1][(j+2)%3]){
                    dp[i][j]+=dp[i-1][(j+1)%3];
                }
                else{
                    dp[i][j]+=dp[i-1][(j+2)%3];
                }
            }
        }
        int token = min(dp[n-1][(t+1)%3], dp[n-1][(t+2)%3]);
        ans = min(ans, token);
    }
    cout<<ans;
    
    return 0;
}