#include <bits/stdc++.h>
using namespace std;
set<int> parent[1001];
set<int> tree[1001];
vector<bool> no_start(1001);
vector<bool> checked(1001);
stack<int> s;
stack<int> ss;
stack<int> sss;
// queue<int> q;
set<int> nums;
int Find(int start){ //10^3
    while(!parent[start].empty()){
        start=*(parent[start].begin());
    }
    return start;
}
void DFS(int start){
    if(checked[start])return;
    if(parent[start].empty()){
        if(checked[start])return;
        checked[start]=1;
        nums.erase(start);
        // cout<<'?';
        cout<<start<<'\n';
        for(auto i : tree[start]){
            parent[i].erase(start);
            ss.push(i);
        }
        // DFS(i);
    }
    else{
        vector<int> v;
        for(auto i : parent[start]){
            if(!checked[i])
                v.push_back(i);
        }
        for(auto i : v){
            int found_parent = Find(i);
            parent[start].erase(i);
            ss.push(found_parent);
            // DFS(found_parent);
        }
        checked[start]=1;
        nums.erase(start);
        // if(checked[start])return;
        s.push(start);
        // cout<<start<<'\n';
        for(auto i : tree[start]){
            parent[i].erase(start);
            sss.push(i);
            // DFS(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b,before;
    vector<bool> semi_checked(1001);
    queue<int> qq;
    for(int i=0; i<m; i++){
        cin>>a;
        for(int j=0; j<a; j++){
            cin>>b;
            if(j!=0){
                if(semi_checked[before]&&semi_checked[b]){
                    // cout<<before<<' '<<b<<'\n';
                    before = b;
                    continue;
                }
                no_start[b]=1;
                parent[b].insert(before);
                tree[before].insert(b);
                qq.push(before);
                qq.push(b);
            }
            before = b;
        }
        while(!qq.empty()){
            semi_checked[qq.front()]=1;
            qq.pop();
        }
    }
    for(int i=1; i<=n; i++){
        nums.insert(i);
    }
    int start;
    for(int i=1; i<=n; i++){
        if(!no_start[i]){
            start = i;
            DFS(i);
            break;
        }
    }
    while(!nums.empty()){
        while(!ss.empty()){
            int temp = ss.top();ss.pop();
            DFS(temp);
        }
        while(!s.empty()){
            cout<<s.top()<<'\n';
            nums.erase(s.top());
            s.pop();
        }
        while(!sss.empty()){
            int temp = sss.top();sss.pop();
            DFS(temp);
        }
    }
    
    return 0;
}