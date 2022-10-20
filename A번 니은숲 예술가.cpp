#define MOD 998244353
#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll no[3001][4];
ll arr[3001];
ll before[3001];
ll dp[3001];
ll ans = 1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>=1 && arr[i]==arr[i-1]){
            cout<<0;
            return 0;
        }
    }
    dp[1]=1;
    dp[2]=4;
    for(int i=3; i<=n; i++){
        int middle = i - before[arr[i]];
        if(middle==i){
            dp[i] = dp[-1]*4%MOD;
            continue;
        }
        else{
            ll now_2 = 4;
            ll now_0 = (pow(4,middle)-4*pow(3,middle)*4);
            ll now_1 = pow(4,middle) - now_0 - now_2;
            ll now = now_0 + now_1 + now_2;
            dp[i] = dp[before[arr[i]]] * now;
            if(i!=n)dp[i]%=MOD;
            before[arr[i]] = i;
        }
    }
    cout<<dp[n]/4%MOD;
    return 0;
}