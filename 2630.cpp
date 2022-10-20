#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std; 
int board[129][129];
int n;
int ans[]={0,0};
void f(pair<int,int>Start, pair<int,int>End){
    if(End.Y-Start.Y==1){
        ans[board[Start.Y][Start.X]]+=1;
        return;
    }
    bool flag = true;
    int token=board[Start.Y][Start.X];
    for(int i=Start.Y; i<End.Y; i++){
        for(int j=Start.X; j<End.X; j++){
            if(board[i][j]!=token){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        ans[token]+=1;
    }
    else{
        int new_start_y = Start.Y+(End.Y-Start.Y)/2;
        int new_start_x = Start.X+(End.X-Start.X)/2;
        f(Start,{new_start_y,new_start_x});
        f({new_start_y,Start.X},{End.Y,new_start_x});
        f({Start.Y,new_start_x},{new_start_y,End.X});
        f({new_start_y,new_start_x},End);
    }
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
    f({0,0},{n,n});
    cout<<ans[0]<<'\n';
    cout<<ans[1];
    return 0;
}