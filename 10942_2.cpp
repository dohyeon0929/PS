#include <bits/stdc++.h>
using namespace std;
int arr[2001];
int dp[2001][2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i][i]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            
        }
    }
    cin>>m;
    int start, end;
    for(int i=0; i<m; i++){
        cin>>start>>end;
    }
    return 0;

}