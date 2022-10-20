//6:30

#include <bits/stdc++.h>
using namespace std;
int n;
int stair[301];
int dp[301];
int cnt[301];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; 
    stair[0]=0;
    dp[0]=0;
    cnt[0]=0;
    for(int i=1; i<=n; i++){
        cin>>stair[i];
    }
    dp[1]=stair[1];
    cnt[1]=1;
    for(int i=2; i<=n; i++){
        if(dp[i-1]>dp[i-2]){
            if(cnt[i-1]<2){
                dp[i]=dp[i-1]+stair[i];
                cnt[i]=cnt[i-1]+1;
                continue;
            }
        }
        dp[i]=dp[i-2]+stair[i];
        cnt[i]=1;
    }
    cout<<dp[n];
    return 0;
}