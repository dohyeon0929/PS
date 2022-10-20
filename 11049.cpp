#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll ans=0;
using pairs = pair<ll,ll>;
vector<ll> prev_v;
vector<ll> prev_pos_v;
vector<ll> v;
vector<ll> next_v;
vector<ll> next_pos_v;
set<pairs> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll a,b,c,d;
    c = -1;
    
    for(int i=0; i<n; i++){ //4
        cin >> a >> b;
        if(i==0)s.insert({a,0});
        prev_v.push_back(c);
        prev_pos_v.push_back(i-1);
        v.push_back(a);
        next_v.push_back(b);
        next_pos_v.push_back(i+1);
        s.insert({b,i+1});
        c=a;
    }
    prev_v.push_back(a);
    prev_pos_v.push_back(n-1);
    v.push_back(b);
    // for(int i=0; i<n+1; i++){
    //     cout<<v[i]<<' ';
    // }
    // cout<<'\n';
    ll nam=n+1;
    for(auto I = s.rbegin(); I!=s.rend(); I++){
        cout<<"nam : "<<nam<<'\n';
        pairs i = *I;
        // cout<<"i : "<<i.first<<'\n';
        // cout<<"i.second : "<<i.second<<'\n';
        if(i.second==0 || i.second ==n)continue;
        auto temp = next(s.begin());
        if(prev_pos_v[i.second]==0||next_pos_v[i.second]==n){
            if(nam>4)
                continue;
            else if(nam==4){
                ll temp1 =  prev_v[(*temp).second]*i.first*next_v[(*temp).second];
                ll temp2 =  prev_v[(*next(temp)).second]*i.first*next_v[(*next(temp)).second];
                if(temp1<temp2)i=*(temp);
                else i=*(next(temp));
            }
        }

        ans+=prev_v[i.second]*i.first*next_v[i.second];
        cout<<ans<<'\n';
        next_pos_v[prev_pos_v[i.second]]=next_pos_v[i.second];
        next_v[prev_pos_v[i.second]]=next_v[i.second];
        
        prev_pos_v[next_pos_v[i.second]]=prev_pos_v[i.second];
        prev_v[next_pos_v[i.second]]=prev_v[i.second];
        
        nam--;
        if(I==s.rend())I=s.rbegin();
        if(nam==3)break;
    }
    cout<<ans;
    return 0;
}