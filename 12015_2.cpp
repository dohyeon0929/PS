#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
vector<pair<int,int>>v;
set<pair<int,int>> s;
int dp[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a;
    fill(arr, arr+1000001,INF);
    fill(dp, dp+1000001,1);
    for(int i=1; i<=n; i++){
        cin>>a;
        v.push_back({a,i});
        // arr[a]=min(arr[a],i);
    }
    // for(int i=1; i<=1000000; i++){
    //     if(arr[i]==INF)continue;
    //     v.push_back({a,i});
    // }
    for(int i=0; i<v.size(); i++){
        s.insert(v[i]);
        auto iter = s.find(v[i]);
        if(iter!=s.begin())
            dp[(*(iter)).first] = dp[(*(prev(iter))).first]+1;
    }
    int MAX=0;
    for(auto i : dp){
        MAX = max(MAX, i);
    }
    for(auto i : s){
        cout<<i.second<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=n; i++){
        cout<<dp[i]<<' ';
    }
    cout<<'\n';
    cout<<MAX;
    return 0;
}