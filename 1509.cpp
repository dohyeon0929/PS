#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
vector<int> v[2500];
int dp[2500];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    fill(dp, dp+2500, INF);
    for(int i=0; i<s.size(); i++){
        v[i].push_back(i);

    }
    dp[0]=1;
    for(int i=0; i<s.size(); i++){
        for(int l=i-1, r=i+1; l>=0 && r<s.size(); l--, r++){
            
            if(s[l]==s[r]){
                v[l].push_back(r);
            } 
            else{
                break;
            }
        }
        for(int l=i-1, r=i; l>=0 && r<s.size(); l--, r++){
            if(s[l]==s[r]){
                v[l].push_back(r);
            } 
            else{
                break;
            }
        }
    }
    for(int i=0; i<s.size(); i++){
        if(dp[i]==INF){
            dp[i]=dp[i-1]+1;
        }
        for(auto j : v[i]){
            // cout<<"i : "<<i<<" j : "<<j<<'\n';
            dp[j]=min(dp[j], dp[i-1]+1);
        }
    }
    int ans = dp[s.size()-1];
    cout<<ans;
    return 0;
}