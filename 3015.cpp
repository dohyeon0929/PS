#define ll long long
#define MAX 500001
#include <bits/stdc++.h>
using namespace std;
ll arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll num;
    ll ans = 0;
    multiset<ll> s;
    set<ll> ss;
    for(int i=0; i<n; i++){ //10^5
        cin>>num;
        if(s.empty()){
            s.insert(num);
            ss.insert(num);
        }
        else{
            auto now = s.find(num);
            int cnt=0;
            int cnt2=0;
            for(auto j = s.begin(); *j<=num && j!=s.end(); j++){
                cnt++;
                cnt2++;
                if(*j == num){
                    cnt2--;
                }
            }
            
            for(int j=0; j<cnt2; j++){
                s.erase(s.begin());
            }
            s.insert(num);
            ss.insert(num);
            if(next(ss.find(num))!=ss.end()){
                cnt++;
            }
            ans+=cnt;
        }
    }
    cout<<ans;
    return 0;
}