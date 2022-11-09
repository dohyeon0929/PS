#include <bits/stdc++.h>
using namespace std;
int arr[102][2];
int dp[10001][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,k;
    cin>>t>>k;
    for(int i=1; i<=k; i++){
        for(int j=0; j<2; j++){
            cin>>arr[i][j];
        }
    }
    // for(int j=0; j<=k; j++){
        dp[0][0]=1; 
    // }
    for(int j=1; j<=k; j++){ //10^4
        for(int i=t; i>=0; i--){ //10^2
            for(int l=0; l<=arr[j][1]; l++){//10^3
                if(i+l*arr[j][0]>t)break;
                dp[i+l*arr[j][0]][j]+=dp[i][j-1];
            }
        }
        for(int i=0; i<=t; i++){
            dp[i][j]+=dp[i][j+1];
        }
    }
    // for(int i=0; i<=t; i++){
    //     for(int j=0; j<=k; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[t][k];
    return 0;
}