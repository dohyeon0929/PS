#define ll long long
#define MAX_SIZE 1000001
//2:10
#include <bits/stdc++.h>
using namespace std;
ll arr[MAX_SIZE];
ll dp[MAX_SIZE];
ll MAX=0;
ll n,m;
ll ans=0;
bool flag = false;
void f(ll start, ll end){
    ll mid = (start+end)/2;
    // cout<<mid<<' ';
    ll idx = lower_bound(arr, arr+n, mid) - arr; 
    ll val = dp[idx] - mid*(n-idx);
    // cout<<val<<'\n'
    if(start==end){
        if(val>=m){
            // if(ans>end){
                ans = max(end,ans);
            // }
        }
        flag=true;
        return;
    }
    if(val<m) f(start, mid);
    else if(val>=m) {
        ans = max(mid, ans);
        f(mid+1, end);
    // }
    // else {
    //     ans = min(ans, mid);
    //     cout<<'?';
    //     f(start,mid);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        MAX=max(arr[i], MAX);
    }
    sort(arr, arr+n);
    dp[n-1]=arr[n-1];
    for(int i=n-2;i>=0; i--){
        dp[i]=dp[i+1]+arr[i];
    }
    f(0,MAX);
    cout<<ans;
    return 0;
}