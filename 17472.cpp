#define INF 123456789
#define Y first
#define X second
//1:15~2:22
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int n,m;
int board[11][11];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int Count=0;
int line_arr[7][7];
bool checked[11][11];
int parent[7];
int level[]={1,1,1,1,1,1,1};
set<pair<int,pairs>> lines;
int Find(int x){
    if(x==parent[x])return x;
    return Find(parent[x]);
}

void number_island(int y, int x){
    Count++;
    queue<pairs> q;
    q.push({y,x});
    board[y][x]=Count;
    checked[y][x]=1;
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
            if(checked[temp.Y][temp.X])continue;
            if(board[temp.Y][temp.X]==0)continue;
            checked[temp.Y][temp.X]=1;
            board[temp.Y][temp.X]=Count;
            q.push({temp.Y, temp.X});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
            line_arr[i][j]=INF;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==1 && !checked[i][j]){
                number_island(i,j);
            }
        }
    }
    int now, before, len_Count, token;
    bool start_Count;
    for(int i=0; i<n; i++){
        start_Count=len_Count=before=0;
        for(int j=0; j<m; j++){
            now = board[i][j];
            if(before!=0 && now==0){
                start_Count=1;
                len_Count=1;
                token = before;
            }
            else if(before==0 && now==0){
                if(start_Count){
                    len_Count+=1;
                }
            }
            else if(before==0 && now!=0){
                if(now!=token){
                    if(len_Count>1){
                        // lines.insert({len_Count, {token, now}});
                        if(token<=now)
                            line_arr[token][now] = min(line_arr[token][now], len_Count);
                        else
                            line_arr[now][token] = min(line_arr[now][token], len_Count);
                        start_Count=0;
                        len_Count=0;
                    }
               }
            }
            else{
                if(token!=now){
                    token = now;
                }
            }
            before=now;
        }
    }
    for(int i=0; i<m; i++){
        start_Count=len_Count=before=0;
        for(int j=0; j<n; j++){
            now = board[j][i];
            if(before!=0 && now==0){
                start_Count=1;
                len_Count=1;
                token = before;
            }
            else if(before==0 && now==0){
                if(start_Count){
                    len_Count+=1;
                }
            }
            else if(before==0 && now!=0){
                if(now!=token){
                    if(len_Count>1){
                        // lines.insert({len_Count, {token, now}});
                        if(token<=now)
                            line_arr[token][now] = min(line_arr[token][now], len_Count);
                        else
                            line_arr[now][token] = min(line_arr[now][token], len_Count);
                        start_Count=0;
                        len_Count=0;
                    }
               }
            }
            else{
                if(token!=now){
                    token = now;
                }
            }
            before=now;
        }
    }

    for(int i=1; i<=Count; i++){
        parent[i]=i;
    }
    for(int i=1; i<=Count; i++){
        for(int j=1; j<=Count; j++){
            if(i<=j){
                if(line_arr[i][j]!=INF){
                    lines.insert({line_arr[i][j], {i,j}});
                }
            }
        }
    }
    int connect_Count=0;
    int ans=0;
    for(auto i : lines){
            // cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<'\n';
        int x = Find(i.second.first);
        int y = Find(i.second.second);
        if(x!=y){
            // cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<'\n';
            if(level[x]<=level[y]){
                parent[x]=y;
            }
            else{
                parent[y]=x;
            }
            ans+=i.first;
            connect_Count++;
        }
        if(connect_Count>=Count-1)break;
    }
    if(connect_Count<Count-1)cout<<-1;
    else cout<<ans;
    return 0;
}