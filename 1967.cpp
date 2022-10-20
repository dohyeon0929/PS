#include <bits/stdc++.h>
using namespace std;
int tree_left[10010];
int tree_right[10010];
vector<int> tree_leaf[10010];
int tree_val[10010];
int tree_jirem[10010];
int tree_max_depth[10010];
int n;
void f(int x){
    if(tree_leaf[x].empty()){
        tree_max_depth[x]=tree_val[x];
        return;
    }
    for(auto i : tree_leaf[x]){
        f(i);
    }
    sort(tree_leaf[x].rbegin(), tree_leaf[x].rend());
    int max1=-1,max2=-1;
    // cout<<"x : "<<x<<'\n';
    for(auto i : tree_leaf[x]){
        // cout<<"tree_max_depth["<<i<<"] : "<<tree_max_depth[i]<<'\n';
        if(max1<tree_max_depth[i]){
            max2=max1;
            max1=tree_max_depth[i];
            
        }
        else if(max2<tree_max_depth[i]){
            max2=tree_max_depth[i];
        }
    }
    // cout<<"max1 : "<<max1<<" max2 : "<<max2<<'\n';
    tree_max_depth[x]=tree_val[x]+max1;
    // cout<<"fin "<<"tree_max_depth["<<x<<"] : "<<tree_max_depth[x]<<'\n';
    if(max2==-1)tree_jirem[x]=max1;
    else tree_jirem[x]=max1+max2;
}
int MAX=0;
void f2(int x){
    for(auto i : tree_leaf[x]){
        f2(i);
    }
    MAX = max(MAX, tree_jirem[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a,b,c;
    fill(tree_left, tree_left+10001, -1);
    fill(tree_right, tree_right+10001, -1);
    fill(tree_val, tree_val+10001, -1);
    tree_val[1]=0;
    for(int i=0; i<=n-2; i++){
        cin>>a>>b>>c; 
        tree_leaf[a].push_back(b);
        tree_val[b]=c;
    }
    f(1);
    f2(1);
    cout<<MAX;
    return 0;
}