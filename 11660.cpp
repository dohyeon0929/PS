#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[1025][1025];
int dp[1025][1025];
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+board[i][j]-dp[i-1][j-1];
        }
    }
    int x1, y1, x2, y2;
    int ans[100001];
    for(int i=0; i<m; i++){
        cin>>x1>>y1>>x2>>y2;
        ans[i]=dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
    }
    for(int i=0; i<m; i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}