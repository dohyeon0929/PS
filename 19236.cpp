#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int dy[]={-1,-1,0,1,1,1,0,-1};
int dx[]={0,-1,-1,-1,0,1,1,1};
int ans=0;
int fish_d[17];
int fish_pos[17][2];
int shark_d;
int shark_pos[2];
int die[17];
int board[4][4];
int save_board[20][4][4];
int now_ans=0;
void turn(int time);
void print(int time){
    cout<<"time : "<<time<<'\n';
    cout<<"num"<<'\n';
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    // cout<<"d"<<'\n';
    // for(int i=0; i<4; i++){
    //     for(int j=0; j<4; j++){
    //         if(board[i][j]==-1)cout<<shark_d<<' ';
    //         else cout<<fish_d[board[i][j]]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
}
void fish_move(int time){
    for(int i=1; i<=16; i++){
        if(die[i])continue;
        pairs cur;
        for(int a=0; a<4; a++){
            for(int b=0; b<4; b++){
                if(board[a][b]==i){
                    cur = {a,b};
                }
            }
        }
        // pairs cur = {fish_pos[i][0], fish_pos[i][1]};
        for(int j=0; j<8; j++){
            pairs tmp = {cur.Y+dy[(fish_d[i]+j)%8], cur.X+dx[(fish_d[i]+j)%8]};
            if(tmp.Y<0||tmp.X<0||tmp.Y>=4||tmp.X>=4)continue;
            if(board[tmp.Y][tmp.X]==-1)continue;
            fish_d[i]=(fish_d[i]+j)%8;
            int target = board[tmp.Y][tmp.X];
            // if(board[tmp.Y][tmp.X]!=0){
            //     swap(fish_pos[i][0], fish_pos[target][0]);
            //     swap(fish_pos[i][1], fish_pos[target][1]);
            // }
            // else{
            //     fish_pos[i][0]=tmp.Y;
            //     fish_pos[i][1]=tmp.X;
            // }
            swap(board[cur.Y][cur.X], board[tmp.Y][tmp.X]);
            break;
        }
        // if(time==1)print(1);
    }
    // copy(&board[0][0], &board[3][3], &save_board[time][0][0]);
    for(int a=0; a<4; a++){
        for(int b=0; b<4; b++){
            save_board[time][a][b]=board[a][b];
        }
    }
}
void shark_move(int time){
    // pairs cur = {shark_pos[0], shark_pos[1]};
    pairs cur;
    for(int a=0; a<4; a++){
        for(int b=0; b<4; b++){
            if(board[a][b]==-1){
                cur = {a,b};
            }
        }
    }
    bool cant_move=true;
    for(int i=1; i<=3; i++){
        // cout<<"shark_d : "<<shark_d<<'\n';
        // for(int a=0; a<4; a++){
        //     for(int b=0; b<4; b++){
        //         cout<<board[a][b]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
        
        pairs tmp = {cur.Y + dy[shark_d]*i, cur.X + dx[shark_d]*i};
        cout<<tmp.Y<<' '<<tmp.X<<'\n';
        cout<<board[tmp.Y][tmp.X]<<'\n';
        if(tmp.Y<0||tmp.X<0||tmp.Y>=4||tmp.X>=4)break;
        if(board[tmp.Y][tmp.X]==0)continue;
        cant_move = false;
        int feed = board[tmp.Y][tmp.X];
        int save_shark_d = shark_d;
        
        now_ans += feed;
        die[feed]=1;
        shark_d = fish_d[feed];
        swap(board[cur.Y][cur.X], board[tmp.Y][tmp.X]);
        board[cur.Y][cur.X]=0;

        print(time);
        turn(time+1);

        now_ans -= feed;
        die[feed]=0;
        shark_d = save_shark_d;
        // cout<<"!!!\n";
        // print(time);
        // copy(&save_board[time][0][0], &save_board[time][3][3], &board[0][0]);
        for(int a=0; a<4; a++){
            for(int b=0; b<4; b++){
                board[a][b]=save_board[time][a][b];
            }
        }
        print(time);
        cout<<'\n';
    }
    if(cant_move){
        ans = max(ans, now_ans);
        cout<<"ans : "<<ans<<'\n';
        return;
    }
}
void turn(int time){
    fish_move(time);
    shark_move(time);
    // print(time);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>a>>b;
            fish_d[a]=b-1;
            // fish_pos[a][0]=i;
            // fish_pos[a][1]=j;
            board[i][j]=a;
        }
    }
    shark_d = fish_d[board[0][0]];
    now_ans+=board[0][0];
    die[board[0][0]]=1;
    board[0][0]=-1;
    cout<<'\n';
    turn(1);
    cout<<ans;
    return 0;
}