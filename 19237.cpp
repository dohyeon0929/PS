// 7 : 47 ~ 9:08   1h 21m 소요
#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
pairs board[21][21]; //[y][x][Time]
int smell[21][21][2]; //[][][0]=번호, [][][1]=냄새 시작 시간대 
int shark_d[401][5][4]; //[번호][방향][우선순위]
int shark_pos[401][3]; //[번호], [0]=y, [1]=x, [2]=방향
set<int> alive;
vector<bool> is_dead(401);
int Time = 0;
int n,m,k;
pairs shark_d_pair(int a){
    if(a==1){
        return {-1,0};
    }
    else if(a==2){
        return {1,0};
    }
    else if(a==3){
        return {0,-1};
    }
    else{
        return {0,1};
    }
}
void print(){
    cout<<"\nfirst\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j].first<<' ';
        }
        cout<<'\n';
    }
    cout<<"second\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j].second<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            board[i][j]={a,0};
            if(board[i][j].first!=0){
                shark_pos[board[i][j].first][0]=i;
                shark_pos[board[i][j].first][1]=j;
                // smell[i][j][0]=board[i][j];
                // smell[i][j][1]=0;
            }
        }
    }
    for(int i=2; i<=m; i++){
        alive.insert(i);
    }
    for(int i=1; i<=m; i++){
        cin>>shark_pos[i][2];
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            for(int k=0; k<4; k++){
                cin>>shark_d[i][j][k];
            }
        }
    }
    while(!alive.empty() && Time!=1000){
        for(int i=m; i>=1; i--){
            if(is_dead[i])continue;
            smell[shark_pos[i][0]][shark_pos[i][1]][0]=i;
            smell[shark_pos[i][0]][shark_pos[i][1]][1]=Time;
        }
        for(int i=m; i>=1; i--){
            if(is_dead[i])continue;
            bool no_nosmell=true;
            pairs cur = {shark_pos[i][0], shark_pos[i][1]};
            for(int j=0; j<4; j++){
                pairs sharkdd = shark_d_pair(shark_d[i][shark_pos[i][2]][j]);
                pairs temp = {cur.Y + sharkdd.Y, cur.X + sharkdd.X};
                if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=n)continue;
                if(smell[temp.Y][temp.X][0]!=0){
                    if(smell[temp.Y][temp.X][1]<=Time-k){
                        smell[temp.Y][temp.X][0]=0;
                        smell[temp.Y][temp.X][1]=0;
                    }
                    else{
                        continue;
                    }
                }
                no_nosmell=false;
                if(board[temp.Y][temp.X].second==Time+1){
                    is_dead[board[temp.Y][temp.X].first]=1;
                    alive.erase(board[temp.Y][temp.X].first);
                }
                board[temp.Y][temp.X]={i,Time+1};
                shark_pos[i][0]=temp.Y;
                shark_pos[i][1]=temp.X;
                shark_pos[i][2]=shark_d[i][shark_pos[i][2]][j];
                break;
            }
            if(no_nosmell){ //냄새 없는 곳이 없을 때 
                pairs cur = {shark_pos[i][0], shark_pos[i][1]};
                for(int j=0; j<4; j++){
                    pairs sharkdd = shark_d_pair(shark_d[i][shark_pos[i][2]][j]);
                    pairs temp = {cur.Y + sharkdd.Y, cur.X + sharkdd.X};
                    if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=n)continue;
                    if(smell[temp.Y][temp.X][0]!=i)continue;
                    if(board[temp.Y][temp.X].second==Time+1){
                        is_dead[board[temp.Y][temp.X].first]=1;
                        alive.erase(board[temp.Y][temp.X].first);
                    }
                    board[temp.Y][temp.X]={i,Time+1};
                    shark_pos[i][0]=temp.Y;
                    shark_pos[i][1]=temp.X;
                    shark_pos[i][2]=shark_d[i][shark_pos[i][2]][j];
                    break;
                }
            }
            //i번째 상어 이동 완료 
        }
        // if(Time==2||Time==3)print();
        Time++;
    }
    // print();
    if(Time==1000 && !alive.empty()){
        cout<<-1;
    }
    else{
        cout<<Time;
    }
    return 0;
}