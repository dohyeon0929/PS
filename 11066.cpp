#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[501][501];
vector<int> v; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    int now;
    ll MAX,ans;
    cin>>t;
    for(int x=0; x<t; x++){
        ans=0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>now;
            v.push_back(now);
        }
        auto pos = v.begin(); 
        auto pos2 = v.begin(); 
        int pos_int = 0;       
        for(int i=0; i<n-1; i++){
            MAX=123456789;
            for(int j=0; j<v.size()-1; j++){
                if(MAX>v[j]+v[j+1]){
                    MAX = v[j]+v[j+1];
                    pos = v.begin()+j;
                    pos_int = j;
                }
            }
            pos2 = pos+1;
            cout<<"pos_int : "<<pos_int<<'\n';
            int temp1 = v[pos_int]+v[pos_int+1];
            v.erase(pos2);
            v.erase(pos);
            v.insert(pos, temp1);
            ans+=MAX;
            cout<<MAX<<'\n';
            for(int j=0; j<v.size(); j++){
                cout<<v[j]<<' ';
            }
            cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}