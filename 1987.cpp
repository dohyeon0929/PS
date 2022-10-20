#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
char board[21][21];
int checked[100];
int d[21][21];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int r,c;
int ans = 1;
void print(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void dfs(pairs cur){
    checked[board[cur.Y][cur.X]]=1;
    for(int i=0; i<4; i++){
        pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
        if(temp.Y<0||temp.X<0||temp.Y>=r||temp.X>=c)continue;
        if(d[temp.Y][temp.X]!=0)continue;
        if(checked[board[temp.Y][temp.X]])continue;
        d[temp.Y][temp.X]=d[cur.Y][cur.X]+1;
        ans = max(ans,d[temp.Y][temp.X]);
        dfs(temp);
        // print();
        d[temp.Y][temp.X]=0;
    }
    checked[board[cur.Y][cur.X]]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a;
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a;
            board[i][j]=a;
        }
    }
    d[0][0]=1;
    dfs({0,0});
    cout<<ans;
    return 0;
}