#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll num=1;
    ll nine=9;
    while(k-nine*num>0){
        k-=nine*num;
        nine*=10;
        num+=1;
    }
    ll ans = pow(10,num-1) + k/num;
    ll namerge = k%num;
    
    if(namerge==0){
        namerge=num;
        ans--;
    }
    string ans_str = " "+to_string(ans);
    char real_ans = ans_str[namerge];
    if(ans>n)cout<<-1;
    else cout<<real_ans;
    return 0;
}