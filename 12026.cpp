#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int dp[1001];
vector<int> v[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    fill(dp, dp+1001, INF);
    for(int i=0; i<s.size(); i++){
        switch(s[i]){
            case 'B':
                v[0].push_back(i);
                break;
            case 'O':
                v[1].push_back(i);
                break;
            case 'J':
                v[2].push_back(i);
                break;
            default:
                break;
        }
    }
    dp[0]=0;
    for(int i=0; i<n; i++){
        int token=0;
        switch(s[i]){
            case 'B':
                token=1;
                break;
            case 'O':
                token=2;
                break;
            case 'J':
                token=0;
                break;
            default:
                break;
        }
        for(auto j : v[token]){
            if(j<i)continue;
            dp[j]=min(dp[j], dp[i]+(j-i)*(j-i));
        }
    }
    if(dp[n-1]!=INF)cout<<dp[n-1];
    else cout<<-1;
    return 0;
}