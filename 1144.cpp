#define INF 123456789
#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int board[10][10];
int distance_board[10][10];
bool checked_distance[82];
bool checked[10][10];
int set_num[10][10];
int set_count = 0;
int n,m;
int set_sum[82];
int graph[82][82];
int minus_graph[82][82];
void bfs(pairs start){
    queue<pairs> q;
    if(board[start.Y][start.X]>0||set_num[start.Y][start.X]>0)return;
    set_count++;
    set_num[start.Y][start.X]=set_count;
    int temp_set_sum=board[start.Y][start.X];
    q.push(start);
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
            if(board[temp.Y][temp.X]>0)continue;
            if(set_num[temp.Y][temp.X]>0)continue;
            q.push(temp);
            temp_set_sum+=board[temp.Y][temp.X];
            set_num[temp.Y][temp.X]=set_num[cur.Y][cur.X];
        }
    }
    set_sum[set_count]=temp_set_sum;
    // cout<<"set_sum["<<set_count<<"] : "<<temp_set_sum<<'\n';
}
void bfs2(pairs start){
    int token = set_num[start.Y][start.X];
    if(checked_distance[token])return;
    checked_distance[token]=1;
    for(int i=0; i<10; i++){
        memset(distance_board[i], 0, sizeof(int)*10);
        memset(checked[i], 0, sizeof(int)*10);
    }
    queue<pairs> q;
    if(board[start.Y][start.X]>0)return;
    q.push(start);
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
            if(set_num[temp.Y][temp.X]==token){
                if(checked[temp.Y][temp.X])continue;
                q.push(temp);
                checked[temp.Y][temp.X]=1;
            }
            else if(board[temp.Y][temp.X]>0){
                if(distance_board[cur.Y][cur.X]==0){
                    distance_board[temp.Y][temp.X]=board[temp.Y][temp.X];
                    q.push(temp);
                }
                else{
                    if(distance_board[temp.Y][temp.X]==0){
                        distance_board[temp.Y][temp.X]=distance_board[cur.Y][cur.X]+board[temp.Y][temp.X];
                        q.push(temp);
                    }
                    else{
                        if(distance_board[cur.Y][cur.X]+board[temp.Y][temp.X]<distance_board[temp.Y][temp.X]){
                            distance_board[temp.Y][temp.X]=distance_board[cur.Y][cur.X]+board[temp.Y][temp.X];
                            q.push(temp);
                        }
                    }
                }
            }
            else{
                if(graph[token][set_num[temp.Y][temp.X]]!=0){
                    graph[token][set_num[temp.Y][temp.X]]=min(graph[token][set_num[temp.Y][temp.X]], distance_board[cur.Y][cur.X]);
                }
                else{
                    graph[token][set_num[temp.Y][temp.X]]=distance_board[cur.Y][cur.X];
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<distance_board[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
}
void floyd(){
    for(int k=1; k<=set_count; k++){
        for(int i=1; i<=set_count; i++){
            for(int j=1; j<=set_count; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
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
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bfs({i,j});
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<set_num[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            graph[i][j]=INF;
            if(i==j)graph[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bfs2({i,j});
        }
    }
    // floyd();
    cout<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<distance_board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=1; i<=set_count; i++){
        for(int j=1; j<=set_count; j++){
            if(i==j)continue;
            minus_graph[i][j]=graph[i][j]+set_sum[j];
        }
        cout<<'\n';
    }
    for(int i=1; i<=set_count; i++){
        for(int j=1; j<=set_count; j++){
            cout<<graph[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=1; i<=set_count; i++){
        for(int j=1; j<=set_count; j++){
            cout<<minus_graph[i][j]<<' ';
        }
        cout<<'\n';
    }
    마이너스 집합 간의 최소 거리 / 플로이드 최소 거리 다 구했으니까
    이제 dp로 답만 도출하며 됨. 
    return 0;
}