#define first Y
#define second X
#include <bits/stdc++.h>
using namespace std;
int ans=0;
bool fin=false;
int board[100][100];
int checked[100][100];
int exposed[100][100];
queue<pair<int,int>> q;
int n,m;
void melt(){
    bool noCheese=true;
    vector<pair<int,int>> melt_soon;
    int dy[]={1,0,-1,0};
    int dx[] = {0,1,0,-1};
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int,int> temp = {cur.Y+dy[i], cur.X+dx[i]};
            if(temp.Y<0||temp.Y>=n||temp.X<0||temp.X>=m)continue;
            if(board[cur.Y][cur.X]==0){
                if(board[temp.Y][temp.X]==1){
                    noCheese=false;
                    exposed[temp.Y][temp.X]+=1;
                    if(exposed[temp.Y][temp.X]==2)
                        melt_soon.push_back({temp.Y,temp.X});
                }
                else{
                    if(checked[temp.Y][temp.X]==1)continue;
                    else{
                        checked[temp.Y][temp.X]=1;
                        q.push(temp);
                    }
                }
            }
        }
    }

    if(noCheese){
        fin=true;
        return;
    }
    ans++;
    for(int i=0; i<melt_soon.size(); i++){
        board[melt_soon[i].Y][melt_soon[i].X]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    } 
    while(!fin){
        memset(checked,0,sizeof(checked));
        memset(exposed,0,sizeof(exposed));
        melt();
    }
    cout<<ans;
    return 0;
}