#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k; 
    cin>>n>>k;
    ll count=1;
    ll tmp;
    ll limit = min((ll)pow(n,2),k);
    for(ll i=2; i<=limit; i++){ //맥시멈 10^9
        ll now=0;
        bool flag = false;
        double sq = sqrt(i);
        if(sq-(ll)sq == 0){
            sq--;
            flag=true;
        }
        // cout<<(ll)sq<<' ';
        for(ll j=1; j<=floor(sq); j++){
            if(i%j!=0)continue;
            tmp=i/j;
            if(j>n || tmp>n)continue;
            // cout<<j<<' '<<tmp<<'\n';
            now++;
        }
        count+=now*2;
        if(flag)count++;
        cout<<count<<' ';
        if(count>=k){
            cout<<'\n';
            cout<<i;
            return 0;
        }
    }
    return 0;
}