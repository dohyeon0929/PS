#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
vector<int> sq_nums;
int dp[200002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i*i<=n; i++){
        sq_nums.push_back(i*i);
    }
    fill(dp, dp+n+1, INF);
    dp[0]=0;
    for(int i=0; i<=n; i++){
        for(auto j : sq_nums){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout<<dp[n];
    return 0;
}