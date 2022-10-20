#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int n;
int board[10][10];
bool used_line2[30];
int used_line2_board[10][10];
int now=0;
int ans=0;
vector<pairs> start_point1;
vector<pairs> start_point2;

void dfs(int point){
    if(point==n*2-1){
        ans = max(ans, now);
        return;
    } 
    if((n*2-2) - point  <= ans - now -1)return;
    pairs tmp = start_point1[point];
    for(int i=0, j=0; tmp.Y+i >=0 && tmp.X+j>=0 && tmp.Y+i <n && tmp.X+j <n; i--, j++){
        pairs cur = {tmp.Y+i, tmp.X+j};
        if(!board[cur.Y][cur.X])continue;
        if(used_line2[used_line2_board[cur.Y][cur.X]])continue;
        used_line2[used_line2_board[cur.Y][cur.X]]=1;
        now+=1;
        dfs(point+1);
        used_line2[used_line2_board[cur.Y][cur.X]]=0;
        now-=1;
    }
    dfs(point+1); //해당 대각선 라인에서 아무 것도 안 할 때 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        start_point1.push_back({i,0});
    }
    for(int i=1; i<n; i++){
        start_point1.push_back({n-1,i});
    }
    for(int i=n-1; i>=0; i--){
        start_point2.push_back({i,0});
    }
    for(int i=1; i<n; i++){
        start_point2.push_back({0,i});
    }
    for(int i=0; i<n*2-1; i++){
        pairs tmp = start_point2[i];
        while(true){
            if(tmp.Y <0 || tmp.X<0|| tmp.Y >=n || tmp.X >=n) break; 
            used_line2_board[tmp.Y][tmp.X] = i;
            tmp = {tmp.Y+1, tmp.X+1};
        }
    }
    dfs(0);
    cout<<ans;
    return 0;
}