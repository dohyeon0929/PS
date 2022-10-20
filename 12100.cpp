#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int save_board[5][20][20];
bool merged[21][21];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int ans;
int n;
void f(int num);
void f2(int a, int i, int j, int num){

    int cury = i;
    int curx = j;
    int tempy = cury+dy[a];
    int tempx = curx+dx[a];
    while(true){
        if(tempy<0||tempx<0||tempy>=n||tempx>=n)break;
        if(board[tempy][tempx]==0||board[tempy][tempx]==board[cury][curx]){
            if(board[tempy][tempx]==0){
                board[tempy][tempx]=board[cury][curx];
            }
            else{
                if(merged[tempy][tempx])break;
                board[tempy][tempx]=board[cury][curx]*2;
                merged[tempy][tempx]=1;
                board[cury][curx]=0;
                break;
            }
            board[cury][curx]=0;
            cury=tempy;
            curx=tempx;
            tempy=cury+dy[a];
            tempx=curx+dx[a];
        }
        else {
            break;
        }
    }
}
void f(int num){
    if(num==5){
        int maxmax=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxmax = max(maxmax, board[i][j]);
            }
        }
        ans = max(ans, maxmax);
        return;
    }
    copy(&board[0][0], &board[0][0]+400, &save_board[num][0][0]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f2(0, i, j, num);
    for(int i=0; i<=n; i++)
        memset(merged[i], 0, sizeof(bool)*20);
    f(num+1);
    copy(&save_board[num][0][0], &save_board[num][0][0]+400, &board[0][0]);
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<n; j++)
            f2(1, j, i, num);
    for(int i=0; i<=n; i++)
        memset(merged[i], 0, sizeof(bool)*20);
    f(num+1);
    copy(&save_board[num][0][0], &save_board[num][0][0]+400, &board[0][0]);

    for(int i=n-1; i>=0; i--)
        for(int j=0; j<n; j++)
            f2(2, i, j, num);
    for(int i=0; i<=n; i++)
        memset(merged[i], 0, sizeof(bool)*20);
    f(num+1);
    copy(&save_board[num][0][0], &save_board[num][0][0]+400, &board[0][0]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f2(3, j, i, num);
    for(int i=0; i<=n; i++)
        memset(merged[i], 0, sizeof(bool)*20);
    f(num+1);
    copy(&save_board[num][0][0], &save_board[num][0][0]+400, &board[0][0]);
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
    for(int i=0; i<=n; i++)
        memset(merged[i], 0, sizeof(bool)*20);
    f(0);
    cout<<ans;
    return 0;
}