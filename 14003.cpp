#define ll long long
#include<bits/stdc++.h>
using namespace std;
int n;
pair<ll,ll> arr[1000001];
pair<ll,ll> sorted_arr[1000001];
ll num[1000001];
pair<ll,ll> parent[1000001];
ll MAX=0;
bool compare(pair<ll, ll>a, pair<ll, ll>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll a;
    for(int i=0; i<n; i++){
        cin>>a;
        arr[i]=sorted_arr[i]=make_pair(a,i);
        num[i]=1;
        parent[i].first = a;
        parent[i].second = 0;
    }
    sort(sorted_arr,sorted_arr+n,compare);
    ll target;
    ll val;
    ll maxmax=0;
    for(int i= n-1; i>=0; i--){
        val=1;
        ll pos = sorted_arr[i].second;
        for(int j=pos+1; j<n; j++){
            if(arr[j].first>sorted_arr[i].first){
                if(val<=num[j]){
                    val = num[j] + 1;
                    parent[sorted_arr[i].second].first = sorted_arr[i].first;
                    parent[sorted_arr[i].second].second=arr[j].second;
                    if(val > MAX)
                        maxmax = pos;
                }
            }
        }
        num[pos]=val;
        // cout<<"val : "<<val<<'\n';
        if(val>MAX){
            MAX = val;
        }
        MAX = max(val,MAX);
    }
    printf("%d\n",MAX);
    // cout<<MAX<<'\n';
    // cout<<parent[maxmax].first<<'\n';
    while(parent[maxmax].second!=0){
        printf("%d ",parent[maxmax].first);
        // cout<<parent[maxmax].first<<' ';
        maxmax = parent[maxmax].second;
    }
    printf("%d\n",parent[maxmax].first);
    // cout<<parent[maxmax].first;
    return 0;
}