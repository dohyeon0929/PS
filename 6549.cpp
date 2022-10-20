#define ll long long
#include <bits/stdc++.h>
using namespace std;
stack<ll> s;
map<ll,int> h; //자기 바로 밑에까지
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(true){
        cin>>n;
        if(n==0)return 0;
        ll num;
        ll ans=0;
        s.push(-2);
        for(int i=0; i<=n; i++){
            if(i!=n)cin>>num;
            else num=-1;
            if(num>s.top()){
                s.push(num);
            }
            else{
                int cnt=0;
                int save_h=0;
                while(num<=s.top()){
                    cnt++;
                    ll now = s.top()*(cnt+h[s.top()]);
                    // cout<<"s.top : "<<s.top()<<" cnt : "<<cnt<<" h[s.top()]"<<h[s.top()]<<'\n';
                    ans = max(ans, now);
                    cnt+=h[s.top()];
                    // save_h += h[s.top()];
                    // if(s.top()==num)save_h = max(save_h, h[num]);
                    h[s.top()]=0;
                    s.pop();
                    // cout<<'?';
                    // cout<<num<<'\n';
                }
                if(num!=-1){
                    s.push(num);
                    // h[num]=cnt+save_h;
                    h[num]=cnt;
                }
                
            }
            // for(int i=1; i<10; i++){
            //     cout<<h[i]<<' ';
            // }
            // cout<<'\n';
        }
        cout<<ans<<'\n';
        ans=num=0;
        while(!s.empty())s.pop();
    }
    return 0;
}