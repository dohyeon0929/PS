//47분 소요
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000 
char board[MAX][MAX]={};
int n;
void func(int start_x, int start_y, int level){
    if(level ==3){
        board[start_y][start_x]='*';
        board[start_y+1][start_x-1] = board[start_y+1][start_x+1]='*';
        for(int i=start_x-2; i<=start_x+2; i++){
            board[start_y+2][i]='*';
        }
        return;
    }
    int next_y = start_y + level/2;
    int left_x = start_x - level/2;
    int right_x = start_x + level/2;
    func(start_x, start_y, level/2);
    func(left_x, next_y, level/2);
    func(right_x, next_y, level/2);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n*2; j++){
            board[i][j]=' ';
        }
    }
    func(n, 1, n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n*2; j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}