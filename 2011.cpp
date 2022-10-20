#define MOD 1000000
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[5001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    dp[0]=dp[1]=1;
    dp[2]=2;
    ll ans=1;
    for(int i=3; i<=5000; i++){
        if(i%2==0){
            dp[i]=dp[i/2]*dp[i/2];
            dp[i]+=dp[i/2-1]*dp[i/2-1];
        }
        else{
            dp[i]=dp[i/2]*dp[i/2+1];
            dp[i]+=dp[i/2-1]*dp[i/2];
        }
        dp[i]%=MOD;
    }
    int Count=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            if(i==0){
                cout<<0;
                return 0;
            }
            if(s[i-1]=='1'||s[i-1]=='2'){
                // cout<<"Count : "<<Count<<'\n';
                ans*=dp[Count-1];
                Count=0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        else{
            if(i==0){
                Count++;
            }
            else{
                if((s[i-1]=='1')||((s[i-1]=='2')&&('1'<=s[i])&&(s[i]<='6'))){
                    Count++;
                }
                else{
                    // cout<<"Count : "<<Count<<'\n';
                    // Count++;
                    ans*=dp[Count];
                    Count=1;
                }
            }
        }
        ans%=MOD;
    }
    // cout<<"Count : "<<Count<<'\n';
    ans*=dp[Count];
    ans%=MOD;
    cout<<ans;
    return 0;
} 