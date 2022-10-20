#define Y first
#define X second
//2:38~3:20 42분 소요
#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,k;
// int dice[7][5] = {{0,0,0,0,0},{0,4,2,5,2},{0,4,3,1,6},
// {0,1,4,5,2},{0,3,1,5,2},{0,4,3,6,1},{0,4,3,2,5}};
int dice[] = {0,0,0,0,0,0,0};
int board[21][21];
int dice_num[7];
int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x>>y>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    int query;
    int now = 1;
    pair<int,int> now_pos = {x,y};
    for(int i=0; i<k; i++){
        cin>>query;
        pair<int,int> temp = {now_pos.Y + dy[query], now_pos.X + dx[query]};
        if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
        now_pos = temp;
        int cur;
        if(query==1){
            cur = dice[1];
            dice[1]=dice[5];
            dice[5]=dice[2];
            dice[2]=dice[6];
            // dice[3]=dice[6];
            // dice[4]=dice[6];
            dice[6]=cur;
        }
        else if(query==2){
            cur = dice[1];
            dice[1]=dice[6];
            dice[6]=dice[2];
            dice[2]=dice[5];
            // dice[3]=dice[6];
            // dice[4]=dice[6];
            dice[5]=cur;
        }
        else if(query==3){
            cur = dice[3];
            // dice[1]=dice[5];
            // dice[2]=dice[6];
            dice[3]=dice[5];
            dice[5]=dice[4];
            dice[4]=dice[6];
            dice[6]=cur;
        }
        else{
            cur = dice[4];
            // dice[1]=dice[5];
            // dice[2]=dice[6];
            dice[4]=dice[5];
            dice[5]=dice[3];
            dice[3]=dice[6];
            dice[6]=cur;
        }
        now = dice[5];
        cout<<now<<'\n';
        if(board[now_pos.Y][now_pos.X]==0) board[now_pos.Y][now_pos.X]= dice[6];
        else {
            dice[6]=board[now_pos.Y][now_pos.X];
            board[now_pos.Y][now_pos.X]=0;
        }
    }
    return 0;
}