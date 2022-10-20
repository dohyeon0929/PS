//225
#include <bits/stdc++.h>
using namespace std;
int t,n;
int arr[2][100001];
int dp[100001][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        for(int j=0; j<=n; j++)
            for(int k=0; k<3; k++)
                dp[j][k]=0;
        for(int j=0; j<2; j++){
            for(int k=0; k<n; k++){
                cin>>arr[j][k];
            }
        }
        dp[0][0]=arr[0][0];
        dp[0][1]=arr[1][0];
        dp[0][2]=0;
        for(int j=1; j<n; j++){
            dp[j][0]=arr[0][j]+max(dp[j-1][1],dp[j-1][2]);
            dp[j][1]=arr[1][j]+max(dp[j-1][0],dp[j-1][2]);
            dp[j][2]=max(dp[j-1][0],dp[j-1][1]);
        }
        int MAX=0;
        for(int j=0; j<3; j++){
            MAX = max(dp[n-1][j],MAX);
        }
        cout<<MAX<<'\n';
    }
    return 0;
}