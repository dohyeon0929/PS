#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll n,m;
ll arr[10001];
ll real_ans=0;
ll ans=0;
ll no_ans = 123456789;
void f(ll Start, ll End){
    // cout<<"Start : "<<Start<<"  End : "<<End;
    ll temp=0;
    ll mid = (Start+End)/2;
    ll max_money=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=mid){
            temp+=arr[i];
            max_money = max(max_money, arr[i]);
        }
        else{
            temp+=mid;
            max_money = max(max_money, mid);
        }
    }
    if(m>=temp){
        if(mid>ans){
            ans = mid;
            real_ans = max_money;
        }
    }
    // cout<<"  temp : "<<temp<<"  ans : "<<ans<<'\n';
    if(Start==End){
        return;
    }
    if(m-temp>=0) f(mid+1,End);
    else f(Start,mid);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // ans=arr[n-1];
    cin>>m; 
    f(0,m);
    cout<<real_ans;
    return 0;
}