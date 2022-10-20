//2:59
#define Pair pair<int,int>
#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
bool flag=0;
int n;
int ans=0;
char board[101][101];
int checked[101][101];
void bfs(Pair start);
void print();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    for(int a=0; a<2; a++){
        memset(checked,0,sizeof(checked));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(checked[i][j]==0){
                    bfs(make_pair(i,j));
                }
            }
        }
        cout<<ans<<'\n';
        ans=0; flag=1;
    }
    return 0;
}
queue<Pair> q;
void bfs(Pair start){
    int dy[]={1,0,-1,0};
    int dx[]= {0,1,0,-1};
    char token = board[start.Y][start.X];
    q.push(start);
    while(!q.empty()){
        Pair cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            Pair temp = make_pair(cur.Y+dy[i], cur.X+dx[i]);
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.Y>=n) continue;
            if(checked[temp.Y][temp.X]==1)continue;
            if(flag==0){
                if(board[temp.Y][temp.X]!=token){
                    continue;
                }
                else{
                    q.push(temp);
                    checked[temp.Y][temp.X]=1;
                }
            }
            else{
                if(token=='R'||token=='G'){
                    if(board[temp.Y][temp.X]=='R'||board[temp.Y][temp.X]=='G'){
                        q.push(temp);
                        checked[temp.Y][temp.X]=1;
                    }
                    else{
                        continue;
                    }
                }
                else if(token=='B'){
                    if(token!=board[temp.Y][temp.X]){
                        continue;
                    }
                    else{
                        q.push(temp);
                        checked[temp.Y][temp.X]=1;
                    }
                }
            }
            // print();
        } 
    }
    ans+=1;
}
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<checked[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}