//8:09 ~ 
#define Y first
#define X second
#define MAX 10001
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int R,C,M;
int ans=0;
int key_num_r, key_num_c;
int shark_pos[MAX][2];
int shark_d[MAX];
int shark_s[MAX];
int shark_size[MAX];
int shark_time[MAX];
int board[101][101];
bool die[MAX];

void Catch(int num){
    for(int i=1; i<=R; i++){
        if(board[i][num]!=0){
            ans+=shark_size[board[i][num]];
            die[board[i][num]]=1;
            board[i][num]=0;
            break;
        }
    }
}
void Move(){
    for(int i=1; i<=M; i++){
        if(die[i])continue;
        pairs target;
        shark_time[i]++;
        if(board[shark_pos[i][0]][shark_pos[i][1]]==i){
            board[shark_pos[i][0]][shark_pos[i][1]]=0;
        }
        if(shark_d[i]==3 || shark_d[i]==4){
            int now = shark_s[i] % key_num_c;
            int left = shark_pos[i][1]-1;
            int right = C - left - 1; 
            if(shark_d[i]==4){
                if(now <= left){
                    target = {shark_pos[i][0], shark_pos[i][1] - now};
                }
                else if(left < now && now<=left*2){
                    target = {shark_pos[i][0], now-left+1};
                    shark_d[i]=3;
                }
                else if(left*2 < now && now <= left*2 + right){
                    target = {shark_pos[i][0], shark_pos[i][1] + now - left*2};
                    shark_d[i]=3;
                }
                else{
                    target = {shark_pos[i][0], C - (now - left*2 - right)};
                }
            }
            else{
                if(now <= right){
                    target = {shark_pos[i][0], shark_pos[i][1] + now};
                }
                else if(right < now && now<=right*2){
                    target = {shark_pos[i][0], C - (now-right)};
                    shark_d[i]=4;
                }
                else if(right*2 < now && now <= right*2 + left){
                    target = {shark_pos[i][0], shark_pos[i][1] - (now - right*2)};
                    shark_d[i]=4;
                }
                else{
                    target = {shark_pos[i][0], now - right*2 - left+1};
                }
            }
            
        }
        else{
            int now = shark_s[i] % key_num_r;
            int up = shark_pos[i][0]-1;
            int down = R - up - 1; 
            if(shark_d[i]==1){
                if(now <= up){
                    target = {shark_pos[i][0]-now, shark_pos[i][1]};
                }
                else if(up < now && now<=up*2){
                    target = {now-up+1, shark_pos[i][1]};
                    shark_d[i]=2;
                }
                else if(up*2 < now && now <= up*2 + down){
                    target = {shark_pos[i][0] + now -up*2, shark_pos[i][1]};
                    shark_d[i]=2;
                }
                else{
                    target = {R - (now - up*2 - down) , shark_pos[i][1]};
                }
            }
            else{
                if(now <= down){
                    target = {shark_pos[i][0] + now, shark_pos[i][1]};
                }
                else if(down < now && now<=down*2){
                    target = {R - (now - down),shark_pos[i][1]};
                    shark_d[i]=1;
                }
                else if(down*2 < now && now <= down*2 + up){
                    target = {shark_pos[i][0] - (now - down*2), shark_pos[i][1]};
                    shark_d[i]=1;
                }
                else{
                    target = {now - down*2 - up+1, shark_pos[i][1]};
                }
            }
        }
        shark_pos[i][0]=target.Y; shark_pos[i][1]=target.X;
        if(board[target.Y][target.X]!=0){
            if(shark_time[board[target.Y][target.X]]< shark_time[i]){
                board[target.Y][target.X] = i;
            }
            else if(shark_size[board[target.Y][target.X]] < shark_size[i]){
                die[board[target.Y][target.X]]=1;
                board[target.Y][target.X] = i;
            }
            else{
                die[i]=1;
            }
        }
        else{
            board[target.Y][target.X]=i;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C>>M;
    key_num_r = R*2-2;
    key_num_c = C*2-2;
    int r,c,s,d,z;
    for(int i=1; i<=M; i++){
        cin>>shark_pos[i][0]>>shark_pos[i][1]>>shark_s[i]>>shark_d[i]>>shark_size[i];
        board[shark_pos[i][0]][shark_pos[i][1]]=i;
    }
    for(int i=1; i<=C; i++){
        Catch(i);
        Move();
    }
    cout<<ans;
    return 0;
}