#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int n,m,ans;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int board[1001][1001];
int d[1001][1001];
int d2[1001][1001];
vector<pairs> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin>>a;
            board[i][j]=a-'0';
            if(board[i][j]==1){
                v.push_back({i,j});
            }
            d[i][j]=-1;
            d2[i][j]=-1;
        }
    }
    d[0][0]=1;
    d2[n-1][m-1]=0;
    queue<pairs> q;
    q.push({0,0});
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y + dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.X>=m)continue;
            if(d[temp.Y][temp.X]!=-1)continue;
            d[temp.Y][temp.X]=d[cur.Y][cur.X]+1;
            if(board[temp.Y][temp.X]==1)continue;
            q.push({temp});
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<d[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    q.push({n-1,m-1});
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y + dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.X>=m)continue;
            if(d2[temp.Y][temp.X]!=-1)continue;
            d2[temp.Y][temp.X]=d2[cur.Y][cur.X]+1;
            if(board[temp.Y][temp.X]==1)continue;
            q.push({temp});
        }
    }
    if(d[n-1][m-1]!=-1&&d2[0][0]!=-1) ans=d[n-1][m-1];
    else ans = 123456789;
    for(auto i : v){
        if(d[i.Y][i.X]==-1||d2[i.Y][i.X]==-1)continue;
        ans = min(ans, d[i.Y][i.X]+d2[i.Y][i.X]);
    }
    if(ans==123456789) ans=-1;
    cout<<ans;
}