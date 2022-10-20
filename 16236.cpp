#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[25][25];
int food[7]={0,0,0,0,0,0,0};
int n, shark_size=2, ate=0,d=0;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
bool vis[25][25];
int dist[25][25];
queue<pair<int,int>> q;
vector<pair<int,int>> hubo;
void BFS(int startx, int starty);
bool isNoFood();
void prints();
pair<int,int> func(int startx,int starty);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int startx,starty;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                startx=i; starty=j;
            }
            else if(board[i][j]!=0){
                food[board[i][j]]+=1;
            }
        }
    }
    // prints();
    BFS(startx,starty);
    cout<<d;
    return 0;
}
void BFS(int startx, int starty){
    int tempDist=1000;
    while(!q.empty()){
        q.pop();
    }
    // q=queue<pair<int,int>>();
    q.push({startx,starty});
    board[startx][starty]=0;
    // prints();
    if(isNoFood())return;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vis[i][j]=0;
            dist[i][j]=0;
        }
    }
    vis[startx][starty]=true;
    while(!q.empty()){
        pair<int,int>cur = q.front();q.pop();
        // prints();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            // cout<<"nx : "<<nx<<"  ny : "<<ny<<'\n';
            if(nx<0||ny>=n||ny<0||ny>=n)continue;
            // for(int i=0; i<n;i++){
            //     for(int j=0; j<n; j++){
            //         cout<<vis[i][j]<<' ';
            //     }
            //     cout<<'\n';
            // }
            // cout<<'?';
            if(vis[nx][ny]==true)continue;
            // cout<<'?';
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            // cout<<"dist\n";
            // for(int i=0; i<n;i++){
            //     for(int j=0; j<n; j++){
            //         cout<<dist[i][j];
            //     }
            //     cout<<'\n';
            // }
            if(tempDist<dist[nx][ny]){
                pair<int,int> next=func(startx, starty);
                nx=next.X;
                ny=next.Y;
                ate+=1;
                d+=dist[nx][ny];
                food[board[nx][ny]]--;
                if(ate==shark_size){
                    shark_size+=1;
                    ate=0;
                }
                // prints();
                hubo.clear();
                BFS(nx,ny);
                return;
            }
            if(board[nx][ny]>shark_size){
                vis[nx][ny]=true;
            }
            else if(board[nx][ny]<shark_size&&board[nx][ny]!=0){
                if(tempDist>=dist[nx][ny]){
                    tempDist=dist[nx][ny];
                    vis[nx][ny]=true;
                    hubo.push_back({nx,ny});
                    q.push({nx,ny});
                }
                // else{
                //     cout<<"????";
                //     pair<int,int> next=func(startx, starty);
                //     nx=next.X;
                //     ny=next.Y;
                //     cout<<"next : "<<nx<<' '<<ny<<'\n';

                //     ate+=1;
                //     d+=dist[nx][ny];
                //     food[board[nx][ny]]--;
                //     if(ate==shark_size){
                //         shark_size+=1;
                //         ate=0;
                //     }
                //     // prints();
                //     hubo.clear();
                //     BFS(nx,ny);
                // }
            }
            else{
                vis[nx][ny]=true;
                q.push({nx,ny});
                // prints();
            }
        }
    }
    if(tempDist!=1000){
        pair<int,int> next=func(startx, starty);
        int nx=next.X;
        int ny=next.Y;
        ate+=1;
        d+=dist[nx][ny];
        food[board[nx][ny]]--;
        if(ate==shark_size){
            shark_size+=1;
            ate=0;
        }
        // prints();
        hubo.clear();
        BFS(nx,ny);
        return;

    }
}
bool isNoFood(){
    int foods=0;
    // cout<<"shark_size : "<<shark_size;
    for(int i=1; i<min(7,shark_size); i++){
        foods+=food[i];
        // cout<<food[i]<<' ';
    }
    // cout<<endl;
    if(foods==0)return true;
    else return false;
}
void prints(){
    cout<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}

pair<int,int> func(int startx,int starty){
    int top=21;
    int left=100;
    int ansx;
    int ansy;
    for(int i=0; i<hubo.size(); i++){
        if(hubo[i].X<top){
            ansx=hubo[i].X;
            ansy=hubo[i].Y;
            top=hubo[i].X;
            left=hubo[i].Y;
        }
        else if(hubo[i].X==top){
            if(hubo[i].Y<left){
                ansx=hubo[i].X;
                ansy=hubo[i].Y;
                top=hubo[i].X;
                left=hubo[i].Y;
            }
        }
    }
    return {ansx,ansy};
}