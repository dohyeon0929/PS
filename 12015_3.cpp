#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[1000001];
vector<ll> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    v.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]>*(prev(v.end()))){
            // cout<<*(prev(v.end()))<<'\n';
            v.push_back(arr[i]);
            // for(int j=0; j<v.size(); j++){
            //     cout<<v[j]<<' ';
            // }
            // cout<<'\n';
        }
        else{
            auto temp = lower_bound(v.begin(),v.end(),arr[i]);
            *temp=arr[i];
        }
    }
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<' ';
    // }
    // cout<<'\n';
    cout<<v.size();
    return 0;
}