//11:40~
#define MAX 4000002
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[MAX];
int parent[MAX];
int next_num[MAX];
int next_idx[MAX];
int Find(int x){
    if(x==parent[x])return x;
    int y = Find(parent[x]);
    parent[x]=y;
    return y;
}
void Union(int a, int b){
    int x = Find(a);
    int y = Find(b);
    parent[x]=y;
    next_idx[x] = next_idx[y];
}
void Pick(int x){
    x = Find(x);
    // cout<<next_idx[x]<<'\n';
    //     cout<<arr[3]<<'\n';
    // cout<<arr[3];
    cout<<arr[next_idx[x]]<<'\n';
    // if(x==arr[next_idx[x]]){
    //     next_idx[x]++;
    // }
    Union(x,arr[next_idx[x]+1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+m);
    for(int i=0; i<=m; i++){
        next_num[arr[i]]=arr[i];
        next_idx[arr[i]]=i;
        parent[arr[i]]=arr[i];
    }
    // for(int i=0; i<m; i++){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<"\n\n";
    int card;
    for(int i=0; i<k; i++){
        cin>>card;
        auto tmp = upper_bound(arr, arr+m, card);
        // cout<<"*tmp : "<<*tmp<<'\n';
        // if(tmp-arr>m)Pick(arr[0]); 
        // else{
        // cout<<*tmp<<'\n';
        Pick(*tmp);
        // }
        // cout<<"next_num\n";
        // for(int j=0; j<m; j++){
        //     cout<<arr[next_idx[Find(arr[j])]]<<' ';
        // }
        // cout<<'\n';
        // cout<<'\n';
    }
    return 0;
}