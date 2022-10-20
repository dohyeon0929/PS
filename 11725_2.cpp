#include <bits/stdc++.h>
using namespace std;
int n;
set<int> t[100001];
int checked[100001];
int parent[100001];
void f(int root);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; 
    int a,b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        t[a].insert(b);
        t[b].insert(a);
    }
    checked[1]=1;
    f(1);
    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
    return 0;
}
queue<int> q;
void f(int root){
    for(auto iter = t[root].begin(); iter!=t[root].end(); iter++){
        if(checked[*iter]!=1){
            // cout<<"*iter : "<<*iter<<'\n';
            parent[*iter]=root;
            checked[*iter]=1;
            f(*iter);
        }
    }
}