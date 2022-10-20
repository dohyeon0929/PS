#define ll long long
#define INF 1000000001
#define MAX 100001
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
pairs tree[410000];
int n,m;
int a[MAX];
pairs init(int start, int end, int node){
    if(start == end)return tree[node] = {a[start],a[start]};
    int mid = (start + end)/2;
    pairs a1 = init(start, mid, node*2);
    pairs a2 = init(mid+1, end, node*2+1);
    return tree[node] = {max(a1.first, a2.first), min(a1.second, a2.second)};
}
pairs f(int start, int end, int node, int left, int right){
    if(left>end||right<start)return {0,INF};
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    pairs a1 = f(start, mid, node*2, left, right);
    pairs a2 = f(mid+1, end, node*2+1, left, right);
    return {max(a1.first, a2.first), min(a1.second, a2.second)};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    init(0, n-1, 1);
    int start, end;
    for(int i=0; i<m; i++){
        cin>>start>>end;
        pairs tmp = f(0, n-1, 1, start-1, end-1);
        cout<<tmp.second<<' '<<tmp.first<<'\n';
    }
    return 0;
}