#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll arr[1000001];
ll a[1000001];
map<ll,ll> Right[1000001];
map<ll,ll> Left[1000001];
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
            v.push_back(arr[i]);
            int temp = distance(v.begin(),prev(v.end()));
            Left[arr[i]]=v[temp-1];
            Right[temp-1]=arr[i];
        }
        else{
            int temp = distance(v.begin(), lower_bound(v.begin(), v.end(), arr[i]));
            v[temp] = arr[i];
            if(temp!=0){
                Left[temp]=v[temp-1];
                Right[temp]=v[temp+1];
                Left[temp+1]=arr[i];
                Right[temp-1]=arr[i];
            }
            else{
                Right[temp]=v[temp+1];
                Left[temp+1]=arr[i];
            }
       }
    }

    cout<<v.size()<<'\n';
    ll now = v[0];
    while(Right[now]!=0){
        cout<<now<<' ';
        ll temp = Right[now];
        now = temp;
    }
    cout<<now;
    return 0;
}