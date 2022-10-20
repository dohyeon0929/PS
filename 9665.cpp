#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
vector<int> dp(1001);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // fill(dp.begin(),dp.end(), INF);
    int target;
    cin>>target;
    dp[1]=dp[3]=1;
    for(int i=2; i<=target; i++){
        if(dp[i-1]==1 || dp[i-3]==1){
            dp[i]=2;
        }
        if(dp[i-1]==2 || dp[i-3]==2){
            dp[i]=1;
        }
    } 
    if(dp[target]==1){
        cout<<"CY";
    }
    else cout<<"SK";
    return 0;
}