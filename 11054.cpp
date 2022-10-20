#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int a[1001];
int b[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]&&a[j]>a[i])a[i]=a[j];
        }
        a[i]++;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[i]&&b[j]>b[i])b[i]=b[j];
        }
        b[i]++;
    }
    int ans=0;
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     cout<<b[i]<<' ';
    // }
    // cout<<'\n';
    
    for(int i=0; i<n; i++){
        ans = max(ans, a[i]+b[i]);
    }
    cout<<ans-1;
    return 0;
}