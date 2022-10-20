#include <bits/stdc++.h>
using namespace std;
int arr[41];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+41);
    
    return 0;
}