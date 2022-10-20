#include <bits/stdc++.h>
using namespace std;
int parent[1001];
set<int> child[1001];
queue<int> q;
queue<int> ans_q;
void func(int start);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,before,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a;
        for(int j=0; j<a; j++){
            cin>>b;
            if(j==0)before = b;
            else{
                if(child[before].find(b)==child[before].end()){
                    child[before].insert(b);
                    parent[b]+=1;
                }
                before=b;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(parent[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp = q.front(); q.pop();
        ans_q.push(temp);
        // cout<<temp<<'\n';
        for(auto i : child[temp]){
            parent[i]--;
            if(parent[i]<=0)q.push(i);
        }
    }
    for(int i=1; i<=n; i++){
        if(parent[i]!=0){
            cout<<0;
            return 0;
        }
    }
    while(!ans_q.empty()){
        cout<<ans_q.front()<<'\n'; ans_q.pop();
    }
    return 0;
}