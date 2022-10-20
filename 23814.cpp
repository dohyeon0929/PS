//7:18
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll d,n,m,k,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>d>>n>>m>>k;
    ll _n = d-n%d;
    ll _m = d-m%d;
    ll _k = k%d;
    ll max = (n+m+k)/d;
    // _k개만큼 n이나 m에 추가 가능?
    int need = max - (n/d+m/d+k/d);
    if(need==2)ans=k-_n-_m;
    else if(need==1&&_n<=_m&&_n<=_k)ans=k-_n;
    else if(need==1&&_n>_m&&_m<=_k)ans=k-_m;
    else if(need==1&&_n+_m<=_k+d&&_n+_m>_k)ans=k-_n-_m;
    else if(need==0)ans=k;
    cout<<ans;
    return 0;
}