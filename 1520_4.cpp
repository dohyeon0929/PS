#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
int n,m;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int dp[502][502];
int board[502][502];
int dfs(int y, int x){
    if(y==n-1&&x==m-1)return 1;
    if(dp[y][x]!=-1)return dp[y][x];
    dp[y][x]=0;
    for(int i=0; i<4; i++){
        int newy=y+dy[i];
        int newx=x+dx[i];
        if(0<=newy&&newy<n&&0<=newx&&newx<m){
            if(board[newy][newx]<board[y][x]){
                dp[y][x]+=dfs(newy, newx);
            }
        }
    }
    return dp[y][x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<dfs(0,0);
    return 0;
}