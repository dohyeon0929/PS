#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
queue<pairs> q;
int board[101][101];
bool checked[101][101];
vector<pairs> location[150];
vector<bool> key_v(150);
vector<bool> door_v(150);
set<char> door;
set<char> key;
string keys;
int ans = 0;
bool block_check(pairs start);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, w, h;
    cin>>tc;
    for(int itc=0; itc<tc; itc++){
        memset(board, 0, sizeof(board));
        memset(checked, 0, sizeof(checked));
        // for(int i=0; i<=100; i++){
        //     fill(board[i], board[i]+101, 0);
        //     fill(checked[i], checked[i]+101, 0);
        // }
        for(int i=0; i<150; i++){
            location[i].clear();
        }
        ans=0;
        door.clear();
        key.clear();
        fill(key_v.begin(), key_v.end(), 0);
        fill(door_v.begin(), door_v.end(), 0);
        // key_v.clear();
        // door_v.clear();
        keys.clear();
        char aaa;
        cin>>h>>w;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>aaa;
                board[i][j]=aaa;
            }
        }
        cin>>keys;
        if(keys!="0"){
            for(int i=0; i<keys.size(); i++){
                key_v[keys[i]]=1;
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(i==0||i==h-1||j==0||j==w-1){
                    if(board[i][j]=='.'){
                        checked[i][j]=1;
                        q.push({i,j});
                    }
                    else if(board[i][j]=='*'){
                        checked[i][j]=1;
                    }
                    else if('A'<=board[i][j]&&board[i][j]<='Z'){
                        checked[i][j]=1;
                        // door.insert(board[i][j]);
                        // door_v[board[i][j]]=1;
                        // location[board[i][j]].push_back({i,j});
                        if(block_check({i,j})){
                            q.push({i,j});
                        }
                    }
                    else if('a'<=board[i][j]&&board[i][j]<='z'){
                        checked[i][j]=1;
                        block_check({i,j});
                        q.push({i,j});
                    }
                    else{//$
                        checked[i][j]=1;
                        // ans+=1;
                        block_check({i,j});
                        q.push({i,j});
                    }
                }
            }
        }
        int dy[]={1,0,-1,0};
        int dx[] = {0,1,0,-1};
        // queue<pairs> qq;
        // for(int i)
        while(!q.empty()){
            pairs cur = q.front(); q.pop();
            for(int i=0; i<4; i++){
                pairs temp = {cur.Y+dy[i], cur.X+dx[i]};
                if(temp.Y<0||temp.X<0||temp.Y>=h||temp.X>=w)continue;
                if(checked[temp.Y][temp.X])continue;
                checked[temp.Y][temp.X]=1;
                if(block_check(temp)){
                    q.push(temp);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
bool block_check(pairs start){
    if('A'<=board[start.Y][start.X]&&board[start.Y][start.X]<='Z'){
        door.insert(board[start.Y][start.X]);
        location[board[start.Y][start.X]].push_back(start);
        if(key_v[board[start.Y][start.X]+32]){ // 안에 있으면 
            door.erase(board[start.Y][start.X]);
            location[board[start.Y][start.X]].clear();
            return 1;
        }
        return 0;
    }
    else if('a'<=board[start.Y][start.X]&&board[start.Y][start.X]<='z'){
        key.insert(board[start.Y][start.X]);
        key_v[board[start.Y][start.X]]=1;
        for(auto i : location[board[start.Y][start.X]-32]){
            q.push(i);
        }
        door.erase(board[start.Y][start.X]-32);
        location[board[start.Y][start.X]-32].clear();
        return 1;
    }
    else if(board[start.Y][start.X]=='.'){
        return 1;
    }
    else if(board[start.Y][start.X]=='*'){
        return 0;
    }
    else{
        ans+=1;
        return 1;
    }
}