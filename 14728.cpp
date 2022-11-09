#define Time first
#define Point second 
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
vector<pairs> v;
int dp[101][10001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    int a,b;
    v.push_back({0,0});
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        pairs p = {a,b};
        v.push_back(p);
    }

    for(int i=1; i<=n; i++){
        for(int j=t; j>=1; j--){
            if(dp[i-1][j]>0){
                if(j+v[i].Time<=t)
                    dp[i][j+v[i].Time] = max(dp[i][j+v[i].Time], dp[i-1][j]+v[i].Point);
                dp[i][j]=max(dp[i-1][j], dp[i][j]);
            }
        }
        dp[i][v[i].Time]=max(dp[i][v[i].Time], v[i].Point);
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=t; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<*max_element(dp[n], dp[n]+t+1);
    return 0;
}