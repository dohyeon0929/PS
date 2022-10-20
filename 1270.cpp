#include <bits/stdc++.h>
using namespace std;

vector<int> t[1001];
queue<int> q;
int n,m,v;
int checked[1001];
void dfs(int v);
void bfs(int v);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>v;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    for(int i=1; i<=n;i++){
        sort(t[i].begin(),t[i].end());
    }
    dfs(v);
    cout<<'\n';
    memset(checked,0,sizeof(checked));
    bfs(v);
    return 0;
}
void dfs(int v){
    checked[v]=1;
    cout<<v<<' ';
    for(auto iter : t[v]){
        if(checked[iter]!=1){
            dfs(iter);
        }
    }
}
void bfs(int v){
    checked[v]=1;
    q.push(v);
    while(!q.empty()){
        int now = q.front();
        cout<<now<<' ';
        q.pop();
        for(auto iter : t[now]){
            if(checked[iter]!=1){
                checked[iter]=1;
                q.push(iter);
            }
        }
    }
}

