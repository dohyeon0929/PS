#include <bits/stdc++.h>
using namespace std;
int arr[21];
int ans = 123456789;
int k;
void f(int value, int num, int l, int r){
    if(num==k+1){
        ans = min(ans, value);
        return;
    }
    f(value+abs(l-arr[num]), num+1, arr[num], r);
    f(value+abs(r-arr[num]), num+1, l, arr[num]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l,r;
    cin>>n>>l>>r>>k;
    for(int i=1; i<=k; i++){
        cin>>arr[i];
    }
    f(0,1,l,r);
    cout<<ans;
    return 0;
}