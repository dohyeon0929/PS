#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[1000001];
map<pair<ll,ll>,pair<ll,ll>> Left;
vector<pair<ll,ll>> v;
bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    v.push_back({arr[0],0});
    for(int i=1; i<n; i++){
        if(arr[i]>(*(prev(v.end()))).first){
            v.push_back({arr[i],i});
            auto temp = prev(v.end());
            Left[{arr[i],i}]=*(prev(temp));
            // Right[*(prev(temp))]=arr[i];
        }
        else{
            pair<ll,ll> ppp= {arr[i],i};
            auto temp = lower_bound(v.begin(), v.end(),ppp, comp);
            *temp = {arr[i],i};
            if(temp!=v.begin()){
                Left[{arr[i],i}]=*(prev(temp));
                // Right[arr[i]]=*(next(temp));
                // Left[*(next(temp))]=arr[i];
                
                // Right[*(prev(temp))]=arr[i];
            }
            // else{
            //     // Right[arr[i]]=*(next(temp));
                
            //     Left[{arr[i],i}]={-1,-1};
            // }
       }
    }

    cout<<v.size()<<'\n';
    pair<ll,ll> now = *(prev(v.end()));
    stack<pair<ll,ll>> s;
    pair<ll,ll> pp = {0,0};
    while(Left[now]!=pp){
        s.push(now);
        pair<ll,ll> temp = Left[now];
        now = temp;
        // cout<<Left[now].first<<' ';
    }
    // cout<<'\n';
    s.push(now);
    while(!s.empty()){
        cout<<(s.top()).first<<' ';
        s.pop();
    }
    return 0;
}