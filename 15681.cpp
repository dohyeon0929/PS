#include <bits/stdc++.h>
using namespace std;
set<int> s[100001];
bool checked[100001];
int dp[100001];
int n,r,q;

int f(int a){
    // cout<<"a : "<<a<<"  dp[a] : "<<dp[a]<<'\n';
    if(dp[a]!=0)return dp[a];
    else{
        int ans = 1;
        for(auto i : s[a]){
            s[i].erase(a);
            ans += f(i);
        }
        dp[a]=ans;
        return dp[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>q;
    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b; 
        s[a].insert(b);
        s[b].insert(a);
    }
    f(r);
    for(int i=0; i<q; i++){
        cin>>a;
        cout<<f(a)<<'\n';
    }
    return 0;
}