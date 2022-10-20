#include <bits/stdc++.h>
using namespace std;
int arr[100001][3];
int dp[100001][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int turn=1;
    while(true){
        cin>>n;
        if(n==0){
            return 0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                cin>>arr[i][j];
            }
        }
        dp[0][0]=2100000000;
        dp[0][1]=arr[0][1];
        dp[0][2]=arr[0][2]+dp[0][1];
        for(int i=1; i<n; i++){
            dp[i][0]=arr[i][0]+min(dp[i-1][0], dp[i-1][1]);
            if(i==1)dp[1][0]=arr[0][1]+arr[1][0];
            dp[i][1]=arr[i][1]+*min_element(dp[i-1], dp[i-1]+3);
            dp[i][2]=arr[i][2]+min(dp[i-1][1], dp[i-1][2]);
            dp[i][1]=min(dp[i][1], dp[i][0]+arr[i][1]);
            dp[i][2]=min(dp[i][2], dp[i][1]+arr[i][2]);
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<3; j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        cout<<turn++<<". "<<dp[n-1][1]<<'\n';
    }
    return 0;
}