#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int board[1001][1001];
int ans_board[1001][1001];
int board_num[1001][1001];
int set_Count_arr[1000001];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int n,m;
int Count=0;
void bfs(pairs start){
    if(board_num[start.Y][start.X]!=0)return;
    Count++;
    int token = Count;
    int set_Count=1;
    queue<pairs> q;
    q.push(start);
    board_num[start.Y][start.X]=token;
    while(!q.empty()){
        pairs cur = q.front();q.pop();
        // cout<<"cur : "<<cur.Y<<' '<<cur.X<<'\n';
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
            if(board_num[temp.Y][temp.X]!=0)continue;
            if(board[temp.Y][temp.X]==1)continue;
            board_num[temp.Y][temp.X]=token;
            set_Count++;
            q.push(temp);
        }
    }   
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<board_num[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    set_Count_arr[token]=set_Count;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    char a;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a;
            board[i][j]=a-'0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==1){
                board_num[i][j]=-1;
            }
            else{
                bfs({i,j});
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<board_num[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i=0; i<=10; i++){
    //     cout<<set_Count_arr[i]<<' ';
    // }
    // cout<<'\n';
    stack<int> s;
    // int checked[1000001];
    set<int> checked;
    int temp_y, temp_x;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==1){
                for(int k=0; k<4; k++){
                    temp_y = i + dy[k];
                    temp_x = j + dx[k];
                    if(temp_y<0||temp_x<0||temp_y>=n||temp_x>=m)continue;
                    if(board[temp_y][temp_x]==1)continue;
                    if(checked.find(board_num[temp_y][temp_x])!=checked.end())continue;
                    checked.insert(board_num[temp_y][temp_x]);
                    ans_board[i][j]+=set_Count_arr[board_num[temp_y][temp_x]];
                }
                ans_board[i][j]++;
                checked.clear();
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ans_board[i][j]%10;
        }
        cout<<'\n';
    }

    return 0;
}