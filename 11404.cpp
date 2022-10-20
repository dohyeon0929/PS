#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int d[101];
int board[101][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(board[a][b]!=0)
            board[a][b] = min(board[a][b],c);
        else
            board[a][b]=c;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j&&board[i][j]==0) board[i][j]=INF;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                board[j][k] = min(board[j][i]+board[i][k],board[j][k]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]==123456789) cout<<0<<' ';
            else cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}