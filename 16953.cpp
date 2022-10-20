#define ll unsigned long long
#include <bits/stdc++.h>
using namespace std;
ll n,m;
ll MIN=123456789;
bool fin=false;
queue<pair<ll,ll>> q;
void f(pair<ll,ll> x){
    if(fin||x.first>m)return;
    ++x.second;
    if(x.first*2==m){
        MIN = min(MIN, x.second);
    }
    else{
        q.push({x.first*2,x.second});
    }
    if(x.first*10+1==m){
        MIN = min(MIN, x.second);
    }
    else{
        q.push({x.first*10+1,x.second});
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    q.push({n,1});
    while(!q.empty()){
        pair<ll,ll>temp = q.front();
        q.pop();
        f(temp);
    }
    if(MIN==123456789)cout<<-1;
    else cout<<MIN;
    return 0;
}