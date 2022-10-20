#define INF 0x7fffffff
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[200001];
int d[200001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<200000; i++){
        if(i>0)adj[i].push_back({1,i-1});
        if(i<m*2)adj[i].push_back({1,i+1});
        if(i<=m&&i!=0) adj[i].push_back({0,2*i});
    }
    fill(d,d+200001,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[n]=0;
    pq.push({d[n],n});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.first!=d[cur.second])continue;
        for(auto nxt : adj[cur.second]){
            if(d[cur.second]+nxt.first>=d[nxt.second])continue;
            d[nxt.second] = d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
        // for(int i=0; i<=m; i++){
        //     cout<<d[i]<<' ';
        // }
        // cout<<'\n';
        // cout<<"top : "<<pq.top().second<<'\n';
    }
    cout<<d[m];
    return 0;
}