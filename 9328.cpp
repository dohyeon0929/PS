#define Y first
#define X second
#include <bits/stdc++.h>
// 65 97
using namespace std;
using pairs = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
int n,m;
char board[101][101];
bool checked[101][101];
vector<pairs> start_point;
vector<pairs> doors[125];

map<pair<char,pairs>,int> near_out_door_check;
map<char,bool> key;
vector<char> key_v;
queue<char> new_key;
void DFS(pairs start){

    queue<pairs> q;
    q.push(start);
    while(!q.empty()){
        pairs cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(checked[temp.Y][temp.X])continue;
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)continue;
            if(board[temp.Y][temp.X]=='*')continue;
            checked[temp.Y][temp.X]=1;
            if(board[temp.Y][temp.X]=='.'){
                q.push(temp);
            }
            else if('a'<= board[temp.Y][temp.X]||board[temp.Y][temp.X]<='z'){
                q.push(temp);
                key[board[temp.Y][temp.X]]=1;
                key_v.push_back(board[temp.Y][temp.X]);
                new_key.push(key_v);
            }
            else{
                near_out_door_check[{board[temp.Y][temp.X], temp}]=1;
                doors[board[temp.Y][temp.X]].push_back(temp);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    for(int x=0; x<t; x++){
        cin>>n>>m;
        for(char i = 'A'; i<='Z'; i++){
            open_door[i]=0;
            key[(char)(i+32)]=0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>board[i][j];
                if(i==0||j==0){
                    if('A'<=board[i][j]&&board[i][j]<='Z'){
                        near_out_door_check[{board[i][j],{i,j}}]=1;
                        doors[board[i][j]].push_back({i,j});
                    }
                    else if(board[i][j]=='*'){
                        continue;
                    }
                    else{
                        start_point.push_back({i,j});
                    }
                }
            }
        }
        string temp_key;
        cin>>temp_key;
        for(int i=0; i<temp_key.size(); i++){
            key[temp_key[i]]=1;
            key_v.push_back(temp_key[i]);
        }
        for(int i=0; i<start_point.size(); i++){
            DFS(start_point[i], board, checked);
        }
         
    }
    return 0;
}