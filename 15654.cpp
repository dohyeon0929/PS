#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int ans[10];
bool used[10001];
void f(int dep);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    f(0);
    return 0;
}
void f(int dep){
    if(dep==m){
        for(int i=0; i<m; i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(used[arr[i]]!=1){
            ans[dep]=arr[i];
            used[arr[i]]=1;
            f(dep+1);
            used[arr[i]]=0;
        }
    }
}