
//4-4 "경우)에도"  문법 이상함
//5-4-5 상하좌우 설명 모호. 상급좀비 기준 상하좌우를 어떻게 따진다는 것인지?
//5-5 좀비들의 이동은 생성(입력)된 순으로 진행된다 가 더 깔끔한 문장 표현 같음
//벽의 위치 (Wz, Wy)의 범위 필요?
//!!! 만약 벽 사이에 하급 좀비가 끼면 어떻게 되나요? 못다 한 이동을 할 수가 없는데 
#define Y first 
#define X second
#define ROW_WALL 100000
#define COLUMN_WALL 100001
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
class Zombie{
public:
    int y;
    int x;
    int grade;
    int direction;
    int speed;
    pairs pos{
        return {y,x};
    }
}
int n,w,z,D;
string command;
pairs player_pos;
bool dead = false;
int board[26][26];
Zombie zombie[700];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
void input(){
    cin>>n;
    cin>>command;
    int a,b,c;
    cin>>a>>b;
    player_pos = {a,b};
    cin>>w;
    for(int i=0; i<w; i++){
        cin>>a>>b>>c;
        if(c) board[a][b]=COLUMN_WALL;
        else board[a][b]=ROW_WALL;
    }
    cin>>z;
    char aa;
    for(int i=1; i<=z; i++){
        cin>>zombie[i].y>>zombie[i].x>>zombie[i].grade>>aa>>zombie[i].speed;
        board[zombie[i].y][zombie[i].x]=i;
        switch(aa){
            case 'U':
                zombie[i].direction=0;
                break;
            case 'D':
                zombie[i].direction=1;
                break;
            case 'L':
                zombie[i].direction=2;
                break;
            case 'R':
                zombie[i].direction=3;
                break;
        }
    }
    cin>>D;
}
void player_move(int day){
    pairs move;
    char token = command[day-1];
    switch(token){
        case 'U':
            move = {-1,0};
            break;
        case 'D':
            move = {1,0};
            break;
        case 'L':
            move = {0,-1};
            break;
        case 'R':
            move = {0,1};
            break;
        case 'S':
            move = {0,0};
            break;
    }
    pairs tmp = {player_pos.Y+move.Y, player_pos.X+move.X};
    if(tmp.Y>0&&tmp.X>0&&tmp.Y<=n&&tmp.X<=n){
        if(board[tmp.Y][tmp.X]<ROW_WALL){
            player_pos = tmp;
        }
    }
}
void zombie_move(int day){
    for(int i=1; i<=z; i++){
        if(zombie[i].grade==0){
            for(int j=0; j<zombie[i].speed; j++){
                pairs tmp = {zombie[i].y+dy[zombie[i].direction], zombie[i].x+dx[zombie[i].direction]};
                if(tmp.Y<=0||tmp.X<=0||tmp.Y>n||tmp.X>n){

                }
                else if(board[tmp.Y][tmp.X]==ROW_WALL && zombie[i].direction<=1){

                }
                else if(board[tmp.Y][tmp.X]==COLUMN_WALL && zombie[i].direction>=2){

                }

                zombie[i].y = tmp.Y; zombie[i].x = tmp.X;
            }
        }
        else{

        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    for(int i=1; i<=D; i++){
        player_move(i);
        zombie_move();
        if(is_dead()){
            cout<<i<<'\n';
            cout<<"DEAD...";
            return 0;
        }
    } 
    return 0;
}