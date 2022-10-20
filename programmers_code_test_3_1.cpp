#define MAX 100000
#define INF 123456789
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int solution(int N, int number) {
    int dp[MAX+10];
    int answer = INF;
    fill(dp,dp+MAX+10,INF);
    dp[0]=2;
    dp[1]=2;
    dp[N]=1;
    dp[11*N]=2;
    dp[111*N]=3;
    dp[1111*N]=4;
    dp[11111*N]=5;
    int count=2;
    if(N!=1){
        while((int)(pow(N,count))<=MAX){
            dp[(int)(pow(N,count))]=count++;
        }
    }
    for(int i=2; i<=MAX; i++){
        if(dp[i-1]+2<=8){
            dp[i]=min(dp[i],dp[i-1]+2);
        }
        if(dp[i-N]+1<=8 && i>=N){
            dp[i]=min(dp[i],dp[i-N]+1);
        }
        if(dp[i]==INF)continue;
        for(int j=1; j<4; j++){
            if(dp[i]+2*j>8)break;
            if(i-j>=0) dp[i-j]=min(dp[i-j],dp[i]+2*j);
            if(i+j<=MAX) dp[i+j]=min(dp[i+j],dp[i]+2*j);
        }
        for(int j=1; j<=7; j++){
            if(dp[i]+j>8)break;
            if((i-j*N)>=0) dp[i-j*N]=min(dp[i-j*N],dp[i]+j);
            if((i+j*N)<=MAX) dp[i+j*N]=min(dp[i+j*N],dp[i]+j);
        }
        for(int j=1; j<=7; j++){
            if(dp[i]+j>8)break;
            int tmp = (int)pow(N,j);
            if((i*tmp)<=MAX) dp[i*tmp]=min(dp[i*tmp],dp[i]+j);
            if((i/tmp)>=0) dp[i/tmp]=min(dp[i/tmp],dp[i]+j);
        }
        // for(int i=1; i<=22; i++){
        // cout<<dp[i]<<' ';
        // }
        // cout<<'\n';
    }

    answer = dp[number];
    if((answer>8) || (answer == INF))answer=-1;
    // for(int i=1; i<=number; i++){
    //     cout<<dp[i]<<' ';
    // }
    cout<<answer;
    return answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution(5,31168);
    return 0;
}