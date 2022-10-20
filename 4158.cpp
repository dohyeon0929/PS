#define ll long long
#include <bits/stdc++.h>
using namespace std;
// map<ll,bool> mm;
vector<ll> v1;
vector<ll> v2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)return 0;
        ll a;
        v1.clear();
        for(int i=0; i<n; i++){
            cin>>a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        a=0;
        int ans=0;
        ll idx;
        for(int i=0; i<m; i++){
            cin>>a;
            idx = lower_bound(v1.begin(), v1.end(), a) - v1.begin();
            if(v1[idx]==a)ans+=1;
        }
        cout<<ans<<'\n'; 
    }
    return 0;
}