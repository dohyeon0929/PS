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
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(i>=1 && arr[i]==arr[i-1]){
            cout<<0;
            return 0;
        }
    }
    dp[1]=1;
    dp[2]=4;
    before[1]=1;
    before[2]=2;
    for(int i=3; i<=n; i++){
        ll middle = i - before[arr[i]] - 1;
        // cout<<"middle : "<<middle<<'\n';
        if(middle==i-1){
            dp[i] = dp[i-1]*4%MOD;
            // cout<<"11dp["<<i<<"] : "<<dp[i]<<'\n';
            continue;
        }
        else{
            ll now_2 = 4;
            ll now_0 = pow(4,middle)-4*(pow(2,middle)-2)+4;
            if(now_0<0)now_0=0;
            ll now_1 = (pow(4,middle) - now_0 - now_2);
            
            ll now_1 = pow(4,middle)-4*(pow(2,middle)-2)+4;
            ll now_0 = (pow(4,middle) - now_0 - now_2);
            if(now_0<0)now_0=0;
            // cout<<"now_0 : "<<now_0<<" now_1 : "<<now_1<<'\n';
            ll now = now_0*4 + now_1*2 + now_2;
            // cout<<"now : "<<now<<'\n';
            dp[i] = dp[before[arr[i]]] * now;
            if(i!=n)dp[i]%=MOD;
            before[arr[i]] = i;
            // cout<<"dp["<<i<<"] : "<<dp[i]<<'\n';
        }
    }
    cout<<dp[n]/4%MOD;
    return 0;
}