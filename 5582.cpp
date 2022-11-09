#include <bits/stdc++.h>
using namespace std;
int dp[4001][4001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s1[i]==s2[j]){
                if(i!=0)
                    dp[i][j]=max(dp[i-1][j-1]+1, 1);
                else
                    dp[i][j]=1;
                ans=max(ans, dp[i][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}