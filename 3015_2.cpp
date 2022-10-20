#define ll long long
#include <bits/stdc++.h>
using namespace std;
stack<ll> s;
map<ll,int> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll num;
    cin>>num;
    m[num]+=1;
    s.push(num);
    ll ans = 0;
    for(int i=1; i<n; i++){
        cin>>num;
        m[num]+=1;
        ll cnt=0;
        while(num>s.top()){
            m[s.top()]=0;
            s.pop();
            cnt++;
            if(s.empty()){
                break;
            }
        }
        if(!s.empty()){
            if(s.top()>num){
                cnt++;
            }
            else if(s.top()==num){
                cnt+=m[num]-1; //자기 제외 
                if(s.size()!=m[num]-1)cnt++;
                // m[num]=1;
            }
            
        }
        s.push(num);
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}