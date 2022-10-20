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
    for(int i=0; i<n; i++){ //10^2
        q.push(arr1[i]);
        for(auto j=s.begin(); j!=s.end(); j++){ //10^2
            ll now = (*j) + arr1[i];
            string now_str = to_string(now);
            string j_str = to_string(*j);
            auto pos = s.find(now);

            if(pos==s.end()){
                m[now_str]=m[j_str] + arr2[i];
                q.push(now);
            }
            else{
                m[now_str] = min(m[now_str],m[j_str] + arr2[i]);
            }
        }
        while(!q.empty()){
            s.insert(q.front());
            q.pop();
        }
        for(auto j=s.begin(); j!=s.end(); j++){
            cout<<*j<<','<<m[to_string(*j)]<<' ';
        }
        cout<<'\n';
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