#define ll long long
#include <bits/stdc++.h>
using namespace std;
int dp[41];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    ll ans=1;
    int token = 1;
    dp[0]=1; dp[1]=1;
    for(int i=2; i<=40; i++){
        if(i%2==0){
            dp[i]+=dp[i/2]*dp[i/2];
            dp[i]+=dp[i/2-1]*dp[i/2-1];
        }
        else{
            dp[i]+=dp[i/2+1]*dp[i/2];
            dp[i]+=dp[i/2]*dp[i/2-1];
        }
    }
    for(int i=0; i<s.size(); i++){
        if('1'<=s[i] && s[i]<='2' && i!=s.size()-1 ){
            token++;
        }
        else if(s[i]=='3' && i!=s.size()-1 && ('0'<=s[i+1] && s[i+1]<='4')){
            token++;
        }
        else if(s[i]=='0'){
            // cout<<dp[token-2]<<'\n';
            ans *= dp[token-2];
            // cout<<ans<<'\n';
            token=1;
        }
        else{
            ans *= dp[token];
            token=1;
        }
    }
    cout<<ans;
    return 0;
}
