#include <bits/stdc++.h>
using namespace std;
int arr[51];
int dp[51][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s,m;
    cin>>n>>s>>m;
    arr[0]=s;
    dp[0][0]=dp[0][1]=s;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int temp1, temp2;
    for(int i=1; i<=n; i++){
            temp1=temp2=0;
            if(dp[i-1][0]-arr[i]>m||dp[i-1][0]-arr[i]<0){
                temp1=-123456789;
            }
            else{
                temp1 = dp[i-1][0]-arr[i];
            }
            if(dp[i-1][1]-arr[i]>m||dp[i-1][1]-arr[i]<0){
                temp2=-123456789;
            }
            else{
                temp2 = dp[i-1][1]-arr[i];
            }
            if(max(temp1,temp2)==-123456789)dp[i][0]=-123456789;
            else{
                dp[i][0] = max(temp1,temp2);
            }

            temp1=temp2=0;
            if(dp[i-1][0]+arr[i]>m||dp[i-1][0]+arr[i]<0){
                temp1=-123456789;
            }
            else{
                temp1 = dp[i-1][0]+arr[i];
            }
            if(dp[i-1][1]+arr[i]>m||dp[i-1][1]+arr[i]<0){
                temp2=-123456789;
            }
            else{
                temp2 = dp[i-1][1]+arr[i];
            }
            if(max(temp1,temp2)==-123456789)dp[i][1]=-123456789;
            else{
                dp[i][1] = max(temp1,temp2);
            }

            // if(max(dp[i][0],dp[i][1])<-1234567){
            //     cout<<-1;
            //     return 0;
            // }
    }
    for(int i=0; i<2; i++){
        for(int j=1; j<=n; j++){
            cout<<dp[j][i]<<' ';
        }
        cout<<'\n';
    }
    int temp = max(dp[n][0],dp[n][1]);
    if(temp<-12345)cout<<-1;
    else cout<<temp;
    return 0;
}