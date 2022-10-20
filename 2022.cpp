#define ld = long double
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,y,c;
    cin>>x>>y>>c;
    ll start=1, end=max(x,y), m;
    while(abs(start-end)<=pow(10,-4)){
        m = (start+end)/2;
        ld now = sqrt(y^2-m^2)*sqrt(x^2-m^2)/(m^2-sqrt(y^2-m^2));
        if(now<=c){
            end = m-1;
        }
        else{
            start = m + 1;
        }
    }
    cout<<m;
    return 0;
}