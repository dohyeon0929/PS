#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
vector<int> sq_nums;
int dp[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    fill(dp, dp+n+1, INF);
    for(int i=1; i*i<=50000; i++){
        sq_nums.push_back(i*i);
        dp[i*i]=1;
    }
    for(int i=1; i<=n; i++){
        for(auto j : sq_nums){
            dp[i+j]=min(dp[i]+1, dp[i+j]);
        }
    }    
    cout<<dp[n];
    return 0;
}