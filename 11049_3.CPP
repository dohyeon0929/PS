// #define INF 1<<31-1
#define ll long long
#include <bits/stdc++.h>
using namespace std;
vector<ll> v;
ll Prev[511];
ll Next[511];
ll will_remove;
ll dp[511][511];
ll now_abs;
ll ans;
bool deleted[511];
ll n;
void print(){
    cout<<"Prev"<<'\n';
    for(ll i=0; i<=n; i++){
        cout<<Prev[i]<<' ';
    }
    cout<<'\n';
    cout<<"Next"<<'\n';
    for(ll i=0; i<=n; i++){
        cout<<Next[i]<<' ';
    }
    cout<<'\n';
}
ll f(ll x){
    // cout<<"x : "<<x<<'\n';
    // cout<<v[Prev[x]]<<' '<<v[x]<<' '<<v[Next[x]]<<'\n';
    return v[x]*v[Prev[x]]*v[Next[x]];
}
void Swap(ll prev_x, ll x, ll next_x){
    // cout<<"prev and next x : "<<prev_x<<' '<<next_x<<'\n';
        // cout<<"Next[Prev[x]] : "<<Next[Prev[x]]<<'\n';
        // cout<<"Prev[x] : "<<Prev[x]<<'\n';
        // cout<<"Next[x] : "<<Next[x]<<'\n';
    ll Next_Prev_x= Next[prev_x];
    ll Prev_Next_x= Prev[next_x];
    ll Next_x = Next[x];
    ll Prev_x = Prev[x];

    Next[prev_x]=Next_x;
    // cout<<"prev[next[x]] : "<<Prev[Next[x]]<<'\n';
    Prev[next_x]=Prev_x;
    // cout<<"prev[next[x]] : "<<Prev[Next[x]]<<'\n';
    Next[x]=Next_Prev_x;
    Prev[x]=Prev_Next_x;
    // cout<<"Prev[x] : "<<Prev[x]<<'\n';
    // cout<<"temp2 : "<<temp2<<'\n';
        // cout<<"prev[next[x]] : "<<Prev[Next[x]]<<'\n';
        // cout<<"Next[Prev[x]] : "<<Next[Prev[x]]<<'\n';
        // cout<<"Prev[x] : "<<Prev[x]<<'\n';
        // cout<<"Next[x] : "<<Next[x]<<'\n';

    // print();
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll a,b;
    for(ll i=0; i<n; i++){
        cin>>a>>b;
        v.push_back(a);
        Prev[i]=i-1;
        Next[i]=i+1;
        // cout<<"Prev["<<i<<"] : "<<Prev[i]<<'\n';
        // cout<<"Next["<<i<<"] : "<<Next[i]<<'\n';
    }
    v.push_back(b);
    Prev[n]=n-1;
    Next[n]=-1;
    for(ll i=1; i<n; i++){
        dp[0][i]=f(i);
    }
    for(ll i=1; i<n-1; i++){
        now_abs = pow(2,31);
        // cout<<now_abs<<'\n';
        for(ll j=1; j<n; j++){
            if(deleted[j])continue;
            ll Prev_j = Prev[j];
            ll Next_j = Next[j];
            Swap(Prev_j, j, Next_j);
            for(ll k=1; k<n; k++){
                if(k==j)continue;
                if(deleted[k])continue;
                if(dp[i][k]!=0){
                    if(dp[i][k]>f(k)){
                        dp[i][k]=f(k);
                    }
                }
                else{
                    dp[i][k] = f(k);
                }
                if(dp[i][k]-dp[i-1][k]<now_abs){
                    now_abs = dp[i][k]-dp[i-1][k];
                    will_remove = j;
                    // cout<<" i : "<<i<<'\n';
                    // cout<<" j : "<<j<<'\n';
                    // cout<<" k : "<<k<<'\n';
                    // cout<<"dp[i][j]"<<dp[i][j]<<'\n';
                    // cout<<"now_abs : "<<now_abs<<'\n';
                    // cout<<"will_remove : "<<will_remove<<'\n';
                }
            }
            Swap(Prev_j, j, Next_j);
        // cout<<"Prev[will_remove] : "<<Prev[will_remove]<<'\n';
        // cout<<"Next[will_remove] : "<<Next[will_remove]<<'\n';
        }
        // cout<<"i : "<<i<<'\n';
        // cout<<"will_remove : "<<will_remove<<'\n';
        // cout<<"dp[i-1][will_remove] : "<<dp[i-1][will_remove]<<'\n';
        ans+=dp[i-1][will_remove];
        // cout<<"ans : "<<ans<<'\n';
        deleted[will_remove]=1;
        Swap(Prev[will_remove], will_remove, Next[will_remove]);
    }
    for(ll i=1; i<n; i++){
        if(deleted[i]!=1){
            ans+=f(i);
        }
    }
    cout<<ans;
    return 0;
}