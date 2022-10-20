#include <bits/stdc++.h>
using namespace std;
bool checked[1001];
vector<set<int>> g(1001);
vector<set<int>> t(1001);
void DFS(int v, int h);
void BFS(int v);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,v;
    cin>>n>>m>>v;
    int temp1, temp2;
    for(int i=0; i<m; i++){
        cin>>temp1>>temp2;
        g[temp1].insert(temp2);
        g[temp2].insert(temp1);
    }
    t[0].insert(v);
    DFS(v, 0);
    cout<<'\n';
    BFS(v);
    return 0;
}
void DFS(int v, int h){
    // cout<<v<<' ';
    checked[v]=true;
    for(auto it=g[v].begin(); it!=g[v].end(); it++){
        if(checked[*it]==false){
            cout<<"I inserted --> it : "<<*it<<"  checked : "<<checked[*it]<<'\n';
            t[h+1].insert(v);
            // cout<<"\nh+1 : "<<h+1<<"  *it : "<<*it<<'\n';
        }
    }
    for(auto it=g[v].begin(); it!=g[v].end(); it++){

        // cout<<"*it : "<<*it<<" checked[*it] : "<<checked[*it]<<'\n';
        if(checked[*it]==false){
            checked[*it]=true;
            // cout<<"*it : "<<*it<<" checked[*it] : "<<checked[*it]<<'\n';
            DFS(*it, h+1);
        }
    }
    
}
void BFS(int v){
    cout<<"BFS"<<'\n';
    
    for(int i=0; !t[i].empty(); i++){
        for(auto it=t[i].begin(); it!=t[i].end(); it++){
            cout<<*it<<' ';
        }
        cout<<'\n';
        // for(int j=0; j<t[i].size(); j++){
        //     // cout<<"i : "<<i<<'\n';
        //     // cout<<"j : "<<j<<'\n';
        //     cout<<t[i][j]<<' ';

        // }
    } 
}