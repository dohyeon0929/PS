#define ll long long
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<ll,ll>;
ll arr[501][5];
ll dp[501];
set<pairs> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a,b;
    int c=-1;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr[i][0]=i-1;
        arr[i][1]=c;
        arr[i][2]=a;
        arr[i][3]=i+1;
        arr[i][4]=b;
        ll temp = arr[i][1]*arr[i][2]*arr[i][4];
        dp[i]=temp;
        if(i>0)
            s.insert({temp,i});
        c=a;
    }
    arr[n][0]=n-1;
    arr[n][1]=a;
    arr[n][2]=b;
    arr[n][3]=-1;
    arr[n][4]=-1;
    ll ans = 0;
    int now;
    for(int i=1; i<=n-1; i++){//30,1
        ans += (*(s.begin())).first;
        now = (*(s.begin())).second; //1
        cout<<(*(s.begin())).first<<' '<<(*(s.begin())).second<<'\n';
        s.erase(s.begin());
        cout<<(*(s.begin())).first<<' '<<(*(s.begin())).second<<'\n';
        cout<<'\n';
        arr[now+1][0]=arr[now][0];
        arr[now+1][1]=arr[now][1];
        if(now+1!=n){
            s.erase({dp[now+1],now+1});
            dp[now+1] = arr[now+1][1]*arr[now+1][2]*arr[now+1][4];
            s.insert({dp[now+1],now+1});
        }
        
        
        arr[now-1][3]=arr[now][3];
        arr[now-1][4]=arr[now][4];
        if(now-1!=0){
            s.erase({dp[now-1],now-1});
            dp[now-1] = arr[now-1][1]*arr[now-1][2]*arr[now-1][4];
            s.insert({dp[now-1],now-1});
        }

    }
    cout<<ans;

    return 0;
}