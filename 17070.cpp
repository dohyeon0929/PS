#include <bits/stdc++.h>
using namespace std;
int n;
int board[18][18];
int dp_x[18][18];
int dp_y[18][18];
int dp_xy[18][18];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
        }
    }
    dp_x[1][2]=1;
    for(int i=1; i<=n; i++){
        for(int j=3; j<=n; j++){
            if(board[i][j]==1){
                continue;
            }
            dp_x[i][j]+=dp_xy[i][j-1]+dp_x[i][j-1];
            dp_y[i][j]+=dp_xy[i-1][j]+dp_y[i-1][j];
            if(board[i-1][j]!=1&&board[i][j-1]!=1){
                dp_xy[i][j]+=dp_x[i-1][j-1]+dp_y[i-1][j-1]+dp_xy[i-1][j-1];
            }
        }
    }
    cout<<dp_x[n][n]+dp_y[n][n]+dp_xy[n][n];
    return 0;
}