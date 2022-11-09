#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int dp[1001];
vector<pairs> p;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        pairs pp = {a,b};
        p.push_back(pp);
    }
    sort(p.begin(), p.end());
    fill(dp+1, dp+n+1,1);
    for(int i=0; i<m; i++){
        dp[p[i].second]=max(dp[p[i].second], dp[p[i].first]+1);
    }
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<' ';
    }
    return 0;
}