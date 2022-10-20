#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int board[26][26];
int dy[]={-1,0,1,0,0};
int dx[]={0,1,0,-1,0};
int znum;
int day;
int nowday;
int n;
bool isdead=false;
string command;
pairs p_pos;
class Zombie{
    public:
        pairs pos;
        int code;
        int d;
        int s;
};
Zombie z[626]; 
void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void pmove(){
    char token = command[nowday];
    int pd;
    if(token=='U')pd=0;
    else if(token=='R')pd=1;
    else if(token=='D')pd=2;
    else if(token=='L')pd=3;
    else if(token=='S')pd=4;
    pairs tmp = {p_pos.Y+dy[pd], p_pos.X+dx[pd]}; 
    if(tmp.Y<=0||tmp.X<=0||tmp.Y>n||tmp.X>n)return;
    if(board[tmp.Y][tmp.X]==-1)return;
    board[p_pos.Y][p_pos.X]+=1000;
    board[tmp.Y][tmp.X]-=1000;
    p_pos = tmp;
}
void zmove(){
    for(int i=1; i<= znum; i++){
        if(z[i].code==0){
            for(int j=1; j<=z[i].s; j++){
                pairs tmp = {z[i].pos.Y + dy[z[i].d], z[i].pos.X + dx[z[i].d]};
                if(board[tmp.Y][tmp.X]==-1||tmp.Y<=0||tmp.X<=0||tmp.Y>n||tmp.X>n){
                    z[i].d = (z[i].d+2)%4;
                    break;
                }
                else{
                    board[z[i].pos.Y][z[i].pos.X]-=i;
                    board[tmp.Y][tmp.X]+=i;
                    z[i].pos = tmp;
                }
            }
            if(z[i].pos==p_pos)isdead=true;
        }
        else{
            for(int j=1; j<=z[i].s; j++){
                pairs tmp = {z[i].pos.Y + dy[z[i].d], z[i].pos.X + dx[z[i].d]};
                if(board[tmp.Y][tmp.X]==-1||tmp.Y<=0||tmp.X<=0||tmp.Y>n||tmp.X>n){
                    if(board[tmp.Y][tmp.X]==-1){
                        board[tmp.Y][tmp.X]=0;
                    }
                    // cout<<"z[i].pos : "<<z[i].pos.Y<<' '<<z[i].pos.X<<'\n';
                    break;
                }
                else{
                    board[z[i].pos.Y][z[i].pos.X]-=i;
                    board[tmp.Y][tmp.X]+=i;
                    z[i].pos = tmp;
                }
            }
            int maxd = 0;
            int max_wall_num=0;
            for(int k=0; k<4; k++){
                pairs cur = z[i].pos;
                // cout<<i<<' '<<cur.Y<<','<<cur.X<<'\n';
                int wall_num=0;
                while(true){
                    cur = {cur.Y + dy[k], cur.X + dx[k]};
                    // cout<<i<<' '<<wall_num<<' '<<cur.Y<<','<<cur.X<<'\n';
                    if(cur.Y<=0||cur.X<=0||cur.Y>n||cur.X>n)break;
                    if(board[cur.Y][cur.X]==-1){
                        // cout<<"i got "<<cur.Y<<','<<cur.X<<'\n';
                        wall_num++;
                    }
                }
                // cout<<'\n';
                cur = {cur.Y - dy[k], cur.X - dx[k]};
                // cout<<'!'<<i<<' '<<wall_num<<' '<<cur.Y<<','<<cur.X<<'\n';
                if(wall_num > max_wall_num){
                    maxd = k;
                    max_wall_num = wall_num;
                }
            }
            // cout<<maxd<<' '<<max_wall_num<<'\n';
            z[i].d = maxd;
            if(z[i].pos==p_pos)isdead=true;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,num;
    char dd;
    cin>>n;
    cin>>command;
    cin>>a>>b;
    p_pos = {a,b};
    board[a][b]-=1000;
    cin>>num;
    for(int i=1; i<=num; i++){
        cin>>a>>b;
        board[a][b]=-1;
    }
    cin>>znum;
    for(int i=1; i<=znum; i++){
        cin>>a>>b>>z[i].code>>dd>>z[i].s;
        z[i].pos = {a,b};
        board[a][b]+=i;
        if(dd=='U')z[i].d=0;
        else if(dd=='R')z[i].d=1;
        else if(dd=='D')z[i].d=2;
        else if(dd=='L')z[i].d=3;
    }
    cin>>day;
    for(nowday=0; nowday<day; nowday++){
        pmove();
        zmove();
        // print();
        if(isdead){
            cout<<nowday+1<<'\n';
            cout<<"DEAD...";
            return 0;
        }
    }
    cout<<"ALIVE!";
    return 0;
}