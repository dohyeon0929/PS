//3:12~3:16
#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
int dp[1002][1002]={};
int combination(int st,int ed){
    if(ed==1){
        dp[st][ed]=st;
        return st;
    }
    if(st==ed || ed==0){
        dp[st][ed]=1;
        return 1;
    }
    if(dp[st][ed]==0) dp[st][ed]=(combination(st-1,ed-1)+combination(st-1,ed))%MOD;
    return dp[st][ed];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<combination(n,k)%10007;
    return 0;
}
