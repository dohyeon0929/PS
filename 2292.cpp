#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    n--;
    ll cnt=1;
    ll num = 6;
    while(n>0){
        n -= num;
        cnt++;
        num+=6;
    }
    cout<<cnt;
    return 0;
}