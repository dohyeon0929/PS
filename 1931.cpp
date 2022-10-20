#define ll unsigned long long
#include<bits/stdc++.h>
using namespace std;
map<ll,ll> m;
multimap<ll,ll> m2;
multimap<ll,ll> m3;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        if(m.find(b)!=m.end()) { 
            if(a==b)m3.insert({a,b});
            else if(m[b]==b){
                m[b]=a;
                m3.insert({b,b});
            }
            else m[b] = max(m[b],a);
        }
        else{
            m[b]=a;
        }
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        m2.insert({i->first, i->second});
    }
    for(auto i=m3.begin(); i!=m3.end(); i++){
        m2.insert({i->first, i->second});
    }
    ll ans=0;
    ll now=0;
    for(auto i=m2.begin(); i!=m2.end(); i++){
        if(i->second>=now){
            now=i->first; 
            ans+=1;
        } 
    }
    cout<<ans;
    return 0;
}