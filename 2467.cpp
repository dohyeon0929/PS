#define ll long long
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<ll,ll>;
set<pairs> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a>=0){
            s.insert({a,1});
        }
        else{
            s.insert({-a,-1});
        }
        // cout<<a;
    }
    ll ans=2000000001;
    pairs ansans[2];
    for(auto iter = s.rbegin(); iter!=prev(s.rend()); iter++){
        auto nxt_iter = next(iter);
        ll temp;
        temp = (*iter).first*(*iter).second + (*nxt_iter).first*(*nxt_iter).second;
        // if((*iter).second!=(*nxt_iter).second){
        //     temp = (*iter).first*(*iter).second + (*nxt_iter).first*(*nxt_iter).second;
        // }
        // else{
        //     temp = (*iter).first*(*iter).second + (*nxt_iter).first*(*nxt_iter).second;
        // }
        // cout<<temp;
        ll abs_temp;
        abs_temp = max(temp, -temp);
        if(ans>abs_temp){

            ans=abs_temp;
            if((*iter).first*(*iter).second<(*nxt_iter).first*(*nxt_iter).second){
                ansans[0]={(*iter).first, (*iter).second};
                ansans[1]={(*nxt_iter).first, (*nxt_iter).second};
            }
            else{
                ansans[1]={(*iter).first, (*iter).second};
                ansans[0]={(*nxt_iter).first, (*nxt_iter).second};
            }
        }
    }
    // cout<<ans<<'\n';
    cout<<ansans[0].first*ansans[0].second<<' '<<ansans[1].first*ansans[1].second;
    return 0;
}