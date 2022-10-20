#define MOD 1000000000
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int board[201][201];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    fill(board[1], board[1]+n+1, 1);
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                board[i][j]+=board[i-1][j-l];
                board[i][j]%=MOD;
            }
        }
    }
    cout<<board[k][n];
    return 0;
}