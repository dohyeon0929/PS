#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000][3];
int dp[1000][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    for(int i=0; i<3; i++){
        dp[0][i]=arr[0][i];
    }
    int MIN=123456789;
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])+arr[i][j];
        }
    }
    for(int i=0; i<3; i++){
        MIN = min(dp[n-1][i],MIN);
    }
    cout<<MIN;
    return 0;
}