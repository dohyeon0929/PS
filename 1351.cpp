#define ll long long
#include <bits/stdc++.h>
using namespace std;
map<ll,ll> m;
ll n,p,q;
ll f(ll x){
    if(m[x]==0) m[x] = f(x/p) + f(x/q);
    // cout<<"m["<<x<<"] = "<<m[x]<<'\n';
    return m[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p>>q;
    m[0]=1;
    cout<<f(n);
    return 0;
}