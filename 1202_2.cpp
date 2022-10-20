#define ll unsigned long long
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<ll,ll>;
ll n,m;
multiset<pairs> s1;
multiset<ll> s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        s1.insert({a,b});
    }
    for(int i=0; i<m; i++){
        cin>>a;
        s2.insert(a);
    }
    ll ans=0;
    multiset<ll> s3;
    for(auto i : s2){
        // cout<<"count : "<<count<<'\n';
        // cout<<(*(s1.begin())).first<<'\n';
        if(!s1.empty()){
            while((*(s1.begin())).first<=i){
                pairs temp = *(s1.begin());
                // cout<<"temp.second : "<<temp.second<<'\n';
                s1.erase(s1.begin());
                s3.insert(temp.second);
                if(s1.empty())break;
            }
        }
        if(!s3.empty()){
            ans+=*(s3.rbegin());
            s3.erase(prev(s3.end()));
            // cout<<"ans : "<<ans<<'\n';
        }
    }
    cout<<ans;
    return 0;
}