#define ll long long
#define MAX_SIZE 1001
#include <bits/stdc++.h>
using namespace std;
int arr[MAX_SIZE];
ll fixed_dp[MAX_SIZE];
ll take_dp[MAX_SIZE];
set<int> tree[MAX_SIZE];
int t,n,k,w;
void dfs(int start){
    if(tree[start].empty()){
        take_dp[start]=arr[start];
    }
    else{
        bool flag=true;
        for(auto i : tree[start]){
            if(fixed_dp[i]==-1)dfs(i);
            take_dp[start]=max(take_dp[start], take_dp[i]+arr[start]);
        }
    }
    fixed_dp[start]=take_dp[start];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int it = 0; it<t; it++){
        memset(take_dp, -1, sizeof(take_dp));
        memset(fixed_dp, -1, sizeof(fixed_dp));
        for(int i=1; i<=n; i++){
            tree[i].clear();
        }
        cin>>n>>k;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        int a,b;
        for(int i=0; i<k; i++){
            cin>>a>>b;
            tree[b].insert(a);
        }
        cin>>w;
        dfs(w);
        cout<<fixed_dp[w]<<'\n';
    }
    return 0;
}