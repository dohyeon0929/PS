#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
pairs arr[502];
int dp[502][502];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a,b;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j]=INF;
        }
    }
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        arr[i]={a,b};
        dp[i][i]=0;
    } 
    for(int i=2; i<=n; i++){
        dp[i-1][i]=arr[i-1].first*arr[i].first*arr[i].second;
    } 
    for(int j=3; j<=n; j++){
        for(int i=j-2; i>=1; i--){
            for(int k=i;k<=j; k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i].first*arr[k].second*arr[j].second);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[1][n];
    return 0;
}