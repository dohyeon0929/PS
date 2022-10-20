// 11:25 ~ 11:36
#define MAX 32001
#include <bits/stdc++.h>
using namespace std;
vector<int> g[MAX];
set<int> s;
int Lock[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        Lock[b]++;
    }
    for(int i=1; i<=n; i++){
        if(Lock[i]==0)s.insert(i);
    }
    int solved=0;
    while(solved<n){
        int now =*(s.begin());
        cout<<now<<' ';
        s.erase(now);
        for(auto i : g[now]){
            Lock[i]--;
            if(Lock[i]==0){
                s.insert(i);
            }
        }
        solved++;
    }
    return 0;
}