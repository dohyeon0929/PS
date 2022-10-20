#define Y first
#define X second
//10:29 ~ 11:46
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
char board[11][11];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int ans=123456789;
int n,m;
void f(pairs R, pairs B, int Count, int direction){
    if(Count>10)return;
    pairs temp;
    for(int i=0; i<4; i++){

        if(i==direction)continue;
        // cout<<"i : "<<i<<'\n';
        // cout<<"Count : "<<Count<<'\n';
        pairs newR=R;
        pairs newB=B;
        bool crashed=false;
        bool BInHole=false;
        bool RInHole=false;
        while(true){
            temp = {newB.Y+dy[i], newB.X+dx[i]};
            // cout<<temp.Y<<','<<temp.X<<'\n';
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)break;
            if(board[temp.Y][temp.X]=='#')break;
            if(board[temp.Y][temp.X]=='O'){
                BInHole=true;
                break;
            }
            // if(board[temp.Y][temp.X]=='R')crashed=true;
            newB=temp;
        }
        if(BInHole)continue;

        while(true){
            if(newB==newR)crashed=true;
            temp = {newR.Y+dy[i], newR.X+dx[i]};
            if(temp.Y<0||temp.X<0||temp.Y>=n||temp.X>=m)break;
            if(board[temp.Y][temp.X]=='#')break;
            if(board[temp.Y][temp.X]=='O'){
                RInHole=true;
                break;
            }
            // if(board[temp.Y][temp.X]=='R')crashed=true;
            newR=temp;
        }
        bool Rchanged=false;
        if(crashed){
            int dR = abs(newR.Y-R.Y)+abs(newR.X-R.X);
            int dB = abs(newB.Y-B.Y)+abs(newB.X-B.X);
            if(dR>dB){
                // if(newR!=R)
                newR = {newR.Y - dy[i], newR.X - dx[i]};
                // Rchanged = true;
            }
            else {
                // if(newB!=B)
                newB = {newB.Y - dy[i], newB.X - dx[i]};
            }
            // cout<<"newR : "<<newR.Y<<' '<<newR.X<<'\n';
            // cout<<"newB : "<<newB.Y<<' '<<newB.X<<'\n';
            
        }
        // if(Rchanged){
        //     if(board[newR.Y+dy[i]][newR.X+dx[i]]=='O')RInHole=false;
        // }
        if(RInHole){
            ans = min(ans, Count);
            // cout<<"!!! ans : "<<ans<<'\n';
            return;
        }
        // if(i==2){
            // cout<<"newR : "<<newR.Y<<' '<<newR.X<<'\n';
            // cout<<"newB : "<<newB.Y<<' '<<newB.X<<'\n';
            // cout<<'\n';
        // }
        f(newR,newB, Count+1,i);
    } 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    pairs r,b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]=='R')r={i,j};
            else if(board[i][j]=='B')b={i,j};
        }
    }
    f(r,b,1,5);
    if(ans==123456789)cout<<-1;
    else cout<<ans;
    return 0;
}