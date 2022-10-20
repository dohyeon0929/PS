#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[31];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<0;
        return 0;
    }
    int val[31];
    val[0]=1; val[2]=3;
    for(int i=4; i<=30; i+=2){
        val[i]=2;
    }
    // for(int i=2; i<=16; i++){
    dp[0]=1;
    for(int j=2; j<=n; j+=2){
        for(int l=2; l<=j; l+=2){
            dp[j]+=dp[j-l]*val[l];
        }
    }
    // }
    cout<<dp[n];
    return 0;
}