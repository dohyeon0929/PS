#define Y first
#define X second
#define INF 0x7fffffff
#include <bits/stdc++.h>
using namespace std;
int v,e,st;
vector<pair<int,int>> adj[1001];
vector<pair<int,int>> adj2[1001];
int d[1001];
int d2[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e>>st;
    int Start, End, D;
    fill(d,d+v+1,INF);
    fill(d2,d2+v+1,INF);
    while(e--){
        int a,b,c; 
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj2[b].push_back({c,a});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second]!=cur.first)continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second] = d[cur.second]+nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq2;
    d2[st]=0;
    pq2.push({d2[st],st});
    while(!pq2.empty()){
        auto cur = pq2.top(); pq2.pop();
        if(d2[cur.second]!=cur.first)continue;
        for(auto nxt : adj2[cur.second]){
            if(d2[nxt.second]<=d2[cur.second]+nxt.first)continue;
            d2[nxt.second] = d2[cur.second]+nxt.first;
            pq2.push({d2[nxt.second], nxt.second});
        }
    }
    int d3[10009];
    int MAX = 0;
    for(int i=1; i<=v; i++){
        d3[i]=d[i]+d2[i];
        MAX = max(d3[i],MAX);
    }
    cout<<MAX;
    return 0;
}