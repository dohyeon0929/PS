//1:00
#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
int board[50][50];
bool checked[50][50];
int Count = 0;
int t, n, m, k;
void check(pair<int,int> start);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin>>t;
    for(int a=0; a<t; a++){
        Count=0;
        memset(board, 0, sizeof(board));
        memset(checked, 0, sizeof(checked));
        cin>>m>>n>>k;
        for(int i=0; i<k; i++){
            cin>>x>>y;
            board[y][x]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(checked[i][j]==false&&board[i][j]==1)
                    check({i,j});
            }
        }
        cout<<Count<<'\n';
    }
    
    return 0;
}
queue<pair<int,int>> q;
void check(pair<int,int> start){
    int dy[4]={1,0,-1,0};
    int dx[4]={0,1,0,-1};
    q.push(start);
    checked[start.Y][start.X]=1;
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop(); 
        for(int i=0; i<4; i++){
            pair<int,int>temp = make_pair(cur.Y + dy[i], cur.X + dx[i]);
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.X>=m) continue;
            if(board[temp.Y][temp.X]==0)continue;
            if(checked[temp.Y][temp.X])continue;
            checked[temp.Y][temp.X]=1;
            q.push(temp);
        }
    }
    Count+=1;
}