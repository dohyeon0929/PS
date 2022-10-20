#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string a;
string b;
void print(int i,int j){
    if(dp[i][j]==0)return;
    if(b[i-1]==a[j-1]){
        print(i-1, j-1);
        cout<<b[i-1];
    }else dp[i-1][j]>dp[i][j-1]?print(i-1,j):print(i,j-1);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>b;
    int m = a.size();
    int n = b.size();
    char token;
    for(int i=1; i<=n; i++){
        token = b[i-1];
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[j-1]==token){
                dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
            }
        }
    }
    stack<char> s;
    cout<<dp[n][m]<<'\n';
    print(n,m);
    return 0;
}