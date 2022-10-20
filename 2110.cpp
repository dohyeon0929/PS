// 5:47 ~ 6:40
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int n,m;
ll arr[200001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll sai = (arr[n-1] - arr[0]) / m;
    
    return 0;
}