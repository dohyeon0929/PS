#define INF 0x7fffffff
#include <bits/stdc++.h>
using namespace std;
int tc;
int n,m,w;
vector<int> adj[501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    for(int i=0; i<tc; i++){
        cin>>n>>m>>w;
        int a,b,c;
        for(int j=0; j<m+w; j++){
            cin>>a>>b>>c;
            adj[a].push_back({c,b});
            adj[b].push_back({c,a});
        }
        for(int j=0; j<w; j++){
            cin>>a>>b>>c;
            adj[a].push_back({c,b});
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                int cur_node = adj[k][0];
                int next_node = adj[k][1];
                int edge_cost = adj[k][2];
                if(distance[cur_node]!=INF && distance[next_node]>distance[cur_node]+edge_cost){
                    distance[next_node]=distance[cur_node]+edge_cost;
                    if(k==n-1){
                        //음수 순환 존재 
                    }
                }
            }
        }
        if(distance[])
        
    }
    
    return 0;
}