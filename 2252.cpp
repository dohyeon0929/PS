#define child first 
#define parent second
#include <bits/stdc++.h>
using namespace std;
bool start[32001];
bool arr[32001];
bool isPrinted[32001];
vector<pair<set<int>,set<int>>> g(32001);
int n,m;
void func(int i);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<32001; i++){
        start[i]=true;
    }
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].parent.insert(b);
        g[b].child.insert(a);
        start[a]=false; 
    }
    for(int i=1; i<=n; i++){
        if(start[i]){
            func(i);
        }
    }
    return 0;
}
void func(int i){
    if(!g[i].child.empty()){
        for(auto it=g[i].child.begin(); !g[i].child.empty(); ++it){
            func(*it);
            g[i].child.erase(it);
        }
    }
    if(isPrinted[i]==false){
        cout<<i<<' ';
        isPrinted[i]=true;
    }
}