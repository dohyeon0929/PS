#define Y first
#define X second
#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[502][502];
int val[502][502];
int num[502][502];
vector<pair<int,int>> tree[502][502];
void f(pair<int,int>start){
    for(auto i : tree[start.Y][start.X]){
        val[i.Y][i.X]+=val[start.Y][start.X];
        f({i.Y,i.X});
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>board[i][j];
            if(board[i-1][j]>board[i][j]){
                tree[i-1][j].push_back({i-1,j});
                num[i][j]+=1;
            }
            if(board[i][j-1]>board[i][j]){
                tree[i][j-1].push_back({i,j-1});
                num[i][j]+=1;
            }
            if(board[i+1][j]>board[i][j]){
                tree[i+1][j].push_back({i+1,j});
                num[i][j]+=1;
            }
            if(board[i][j+1]>board[i][j]){
                tree[i][j+1].push_back({i,j+1});
                num[i][j]+=1;
            }
        }
    }
    val[1][1]=1;
    f({1,1});
    return 0;
}