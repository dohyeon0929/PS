#define RMAX 1010000
#define MAX 1000001000000
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll sieve[RMAX];
vector<ll> Prime;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ll Min, Max;
    cin>>Min>>Max;
    ll rmax = (ll)(sqrt(Max));
    sieve[0]=sieve[1]=1;
    for(ll i=2; i<=rmax; i++){ //10^6
        if(sieve[i]==0){
            ll num = i*i;
            //pow함수는 왜 안 되는 거지?? 25가 24가 돼 
            Prime.push_back(num);
            for(ll j=i*2; j<=rmax; j+=i){
                sieve[j]=1;
            }
        }
    }
    vector<bool> ans_sieve(1000002);
    ll start = Min;
    int ans=0;
    for(ll i = Min; i<=Max; i++){ //10^6
        if(ans_sieve[i-Min]==1)continue;
        for(auto j : Prime){ //78000개 
            if(i%j==0){
                for(ll k=i; k<=Max; k+=j){
                    if(ans_sieve[k-Min]!=1){
                        // cout<<"k : "<<k<<" j : "<<j<<'\n';
                        ans_sieve[k-Min]=1;
                        ans++;
                    }
                }
                cout<<"check : "<<j<<'\n';
                break;
            }
        }
    }
    // for(auto i : Prime){
    //     for(ll j = Min; j<= Max; j++){

    //     }
    // }
    
    cout<<Max-Min+1-ans;
    return 0;
}