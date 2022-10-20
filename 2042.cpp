#define ll long long
#define MAX_SIZE 4000010
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
ll arr[MAX_SIZE];
ll tree[MAX_SIZE];
void Create(ll start, ll end, ll node, ll Left, ll Right){
    // cout<<"start : "<<start<<"  end : "<<end<<"  node : "<<node<<"  left : "<<Left<<"  Right : "<<Right<<'\n';
    if(end < Left || start> Right)return ;
    if(start==end){
        tree[node]=arr[start];
        return ;
        // cout<<"tree["<<node<<"] : "<<tree[node]<<'\n';
        // return tree[node];
    }
    ll mid = (start+end)/2;
    Create(start, mid, node*2, Left, Right);
    Create(mid+1, end, node*2+1, Left, Right);
    tree[node]=tree[node*2]+tree[node*2+1];
    return ;
    // if(node==2){
    //     cout<<tree[4]<<' '<<tree[5]<<'\n';
    //     tree[2]=tree[4]+tree[5];
    //     cout<<tree[(int)(node)]<<'\n';
    // }
    // cout<<"tree["<<node<<"] : "<<tree[node]<<'\n';
}
void Update(ll start, ll end, ll node, ll target, ll diff){
    // cout<<"start : "<<start<<"  end : "<<end<<"  node : "<<node<<"  target : "<<target<<"  diff : "<<diff<<'\n';
    if(target<start||target>end)return;
    tree[node]+=diff;
    if(start==end)return;
    ll mid = (start+end)/2;
    if(target<=mid)Update(start, mid, node*2, target, diff);
    else Update(mid+1, end, node*2+1, target, diff);
    return;
}
ll Sum(ll start, ll end, ll node, ll target_left, ll target_right){
    // cout<<"start : "<<start<<"  end : "<<end<<"  node : "<<node<<"  target_left : "<<target_left<<"  target_right : "<<target_right<<"  tree[node] : "<<tree[node]<<'\n';
    if(target_left>end||start>target_right)return 0;
    if(start==target_left&&end==target_right)return tree[node];
    if(start==end)return tree[node];
    ll mid = (start+end)/2;
    // if(target_left<mid&&target_right<=end)return Sum(start, mid, node*2, target_left, target_right)+Sum(mid+1, end, node*2+1, target_left, target_right);
    return Sum(start, mid, node*2, target_left, min(mid,target_right))+Sum(mid+1, end, node*2+1, max(mid+1,target_left), target_right);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    Create(1,n,1,1,n);
    // for(int i=1; i<=10; i++){
    //     cout<<tree[i]<<' ';
    // }
    // cout<<'\n';
    ll a,b,c;
    for(int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a==1){//update
            Update(1,n,1,b,c-arr[b]);
            arr[b]=c;
        }
        else{//sum
            cout<<Sum(1,n,1,b,c)<<'\n';
        }
    }
    return 0;
}