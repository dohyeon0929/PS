#define inf 0x7fffffff
#include <bits/stdc++.h>
using namespace std;
int v,e,st;
vector<pair<int,int>> adj[20001];
int d[20001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    cin>>st;
    int a,b,c;
    fill(d,d+20001,inf);
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.first!=d[cur.second])continue;
        for(auto temp : adj[cur.second]){
            if(d[temp.second]<temp.first + d[cur.second])continue;
            d[temp.second]=temp.first + d[cur.second];
            pq.push({d[temp.second],temp.second});
        }
    }
    for(int i=1; i<=v; i++){
        if(d[i]==inf)cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }
    return 0;
}