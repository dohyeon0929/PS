#define ll long long
#include <bits/stdc++.h>
using namespace std;
vector<ll> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll cnt=n;
    ll start = 1, end=k;
    ll mid;
    int ans = 0;
    while(true){
        if(start>end)break;
        mid = (start+end)/2;
        ll cnt=0;
        for(int i=1; i<=n; i++){
            cnt+=min(mid/i,n);
        }
        if(cnt>=k){
            ans=mid;
            end=mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout<<ans;
    return 0;
}