#include <bits/stdc++.h>
using namespace std;
set<int, greater<int>> tree_leaf[100010];
map<int,int> val_hubo[100010];
int tree_val[100010];
int tree_jirem[100010];
int tree_max_depth[100010];
int n;
void f(int x){
    if(tree_leaf[x].empty()){
        tree_max_depth[x]=tree_val[x];
        return;
    }
    for(auto i : tree_leaf[x]){
        f(i);
    }
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
bool up[100010];
void f3(int x){
    // cout<<x<<'\n';
    up[x]=1;
    set<int,greater<int>> save = tree_leaf[x];
    for(auto i: save){
        // cout<<"i : "<<i<<'\n';
        if(up[i]){
            // cout<<"erase "<<i<<'\n';
            tree_leaf[x].erase(i);
            tree_val[x] = max(val_hubo[x][i],tree_val[x]);
                // cout<<"val of "<<x<<" : "<<tree_val[x]<<'\n';
        }
        else {
            f3(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a,b,c;
    // tree_val[1]=0;
    for(int i=1; i<=n; i++){
        cin>>a;
        while(true){
            cin>>b;
            if(b==-1)break;
            cin>>c;
            tree_leaf[a].insert(b);
            val_hubo[b][a]=c;
        }
    }
    f3(1);
    f(1);
    f2(1);
    cout<<MAX;
    return 0;
}