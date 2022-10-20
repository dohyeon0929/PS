// #define MAX 1000001
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll start, end, mid, tmp;
    start = 0; end = (1<<31)-1;
    ll ans=0;
    while(start<=end){
        // cout<<"start : "<<start<<"  end : "<<end<<'\n';
        mid = (start+end)/2;
        tmp=0;
        for(int i=0; i<n; i++){
            tmp +=arr[i]/mid;
        }
        if(tmp>=m)ans=max(ans,mid);
        if(start==end)break;
        if(tmp>=m)start=mid+1;
        else end=mid;
    }
    cout<<ans;
    return 0;
}