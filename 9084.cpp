#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int n;
    cin>>t;
    for(int it=0; it<t; it++){
        cin>>n;
        vector<int> v;
        int x;
        int dp[10001];
        fill(dp, dp+10001,0);
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        int num;
        cin>>num;
        dp[0]=1;
        cout<<dp[0]<<"\n\n";
        for(int i=0; i<=num; i++){
            for(auto j:v){
                if(i+j>num)break;
                dp[i+j]+=dp[i];
            }
            cout<<dp[i]<<' ';
        }
        cout<<'\n';
        cout<<dp[num]<<'\n';
    }
    return 0;
}