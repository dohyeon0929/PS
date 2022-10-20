#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[501][501];
bool checked[501][501];
int dp[501][501];
int ans=0;
void f(pair<int,int> start){
    int dy[]={1,0,-1,0};
    int dx[]={0,1,0,-1};
    pair<int,int>cur = start; 
    if(cur.Y==n&&cur.X==m){
        ans+=1;
        return;
    }
    for(int i=0; i<4; i++){
        pair<int,int> temp = {cur.Y+dy[i], cur.X+dx[i]};
        if(temp.Y<=0||temp.Y>n||temp.X<=0||temp.X>m)continue; 
        if(checked[temp.Y][temp.X]==1||board[temp.Y][temp.X]>=board[cur.Y][cur.X])continue;
        checked[temp.Y][temp.X]=1;
        // dp[cur.Y][cur.X]+=1;
        f(temp);
        checked[temp.Y][temp.X]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>board[i][j];
        }
    }
    checked[1][1]=1;
    f({1,1});
    cout<<ans;    
    return 0;
}