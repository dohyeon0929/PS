#define ll long long
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<ll, ll>;
int arr1[101];
int arr2[101];
set<ll> s;
map<string,ll> m;
queue<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,M;
    cin>>n>>M;
    s.insert({0,0});
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }
    for(int i=0; i<n; i++){
        q.push(arr1[i]);
        for(auto j=s.begin(); j!=s.end(); j++){
            string now = to_string((*j) + arr1[i]);
            auto pos = s.find(stoll(now));
            if(pos==s.end()){
                m[now]=m[to_string(*j)] + arr2[i];
                q.push(stoll(now));
            }
            else{
                m[now] = min(m[now],m[to_string(*j)] + arr2[i]);
            }
        }
        while(!q.empty()){
            s.insert(q.front());
            q.pop();
        }
        // for(auto j=s.begin(); j!=s.end(); j++){
        //     cout<<*j<<','<<m[*j]<<' ';
        // }
        // cout<<'\n';
    }

    ll ans=123456789;
    for(auto i : s){
        if(i>=M){
            ans = min(ans, m[to_string(i)]);
        }
    }
    cout<<ans;
    return 0;
}