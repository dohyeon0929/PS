#define MAX 200001
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[200001];
bool flag = false;
ll n,m;
ll ans=0;
void f(ll Start, ll End){
    // cout<<"start : "<<Start<<"  End : "<<End<<'\n';
    bool too_big = false;
    ll mid = (Start+End)/2;
    ll start = arr[0];
    int start_idx = 0;
    ll num = mid;
    ll tmp=1234567890;
    for(int i=0; i<m-1; i++){
        if(start_idx==n-1){
            too_big=true;
            break;
        }
        int idx = lower_bound(arr+start_idx+1, arr+n, start+num)-arr;
        if(idx==n){
            too_big = true;
            break;
        }
        tmp = min(tmp,arr[idx]-arr[start_idx]);
        start_idx = idx;
        start = arr[idx];
    }
    // if(tmp!=mid)
    if(!too_big) ans = max(ans, tmp);
    if(Start==End)return;
    if(too_big /*|| mid==tmp*/) f(Start, mid);
    else f(mid+1, End);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    f(0, arr[n-1]-arr[0]);
    cout<<ans; 
    return 0;
}