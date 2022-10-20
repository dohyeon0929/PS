#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;

int n;
int Size = 2;
int ans = 0;
int ate=0;
pair<int, int> now;
int fish[7];
int board[20][20];
bool cango[20][20];
int d[20][20];
queue<pair<int,int>> q;

void letsEat(pair<int,int>start);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==9) now = {i,j};
            else fish[board[i][j]]+=1;
        }
    }
    letsEat(now);
    cout<<ans;
    return 0;
}
void letsEat(pair<int,int>start){
    int dy[]={1,0,-1,0};
    int dx[]={0,1,0,-1};
    vector<pair<int,int>> hubo;
    int nearest = 1000;
    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cango[i][j] = true; 
            d[i][j]=0;
        }
    }
    q.push(start);
    cango[start.Y][start.X]=false;
    board[start.Y][start.X]=0;
    d[start.Y][start.X]=0;
    while(!q.empty()&&flag){
        pair<int,int>cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int,int>temp = make_pair(dy[i]+cur.Y, dx[i]+cur.X);
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.X>=n)continue;
            if(board[temp.Y][temp.X]>Size||cango[temp.Y][temp.X]==false)continue;
            d[temp.Y][temp.X]=d[cur.Y][cur.X]+1;
            cango[temp.Y][temp.X]=false;
            q.push({temp.Y, temp.X});
            if(board[temp.Y][temp.X]==0)continue;
            if(board[temp.Y][temp.X]<Size&&nearest>=d[temp.Y][temp.X]){
                hubo.push_back({temp.Y,temp.X});
                nearest = d[temp.Y][temp.X];
            }
        }
    }
    
    if(hubo.empty()) return;
    sort(hubo.begin(), hubo.end());
    fish[board[hubo[0].Y][hubo[0].X]]-=1;
    board[hubo[0].Y][hubo[0].X]=0;
    ans+=d[hubo[0].Y][hubo[0].X];
    if(Size==++ate){
        Size+=1;
        ate=0;
    }
    for(int i=1; i<Size; i++){
        if(fish[i]>0){
            letsEat(hubo[0]);
            break;
        }
    }
    return;
}
