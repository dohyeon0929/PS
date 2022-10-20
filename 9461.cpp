#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    ll dp[101];
    dp[1]=dp[2]=dp[3]=1;
    dp[4]=dp[5]=2;
    for(int i=6; i<=100; i++){
        dp[i]=dp[i-1]+dp[i-5];
    }
    int num;
    for(int i=0; i<t; i++){
        cin>>num;
        cout<<dp[num]<<'\n';
    }
    return 0;
}