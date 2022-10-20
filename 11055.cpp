#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int a[1001];
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
            if(arr[i]>arr[j]&&a[i]<a[j])a[i]=a[j];
        }
        a[i]+=arr[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(ans, a[i]);
    }
    cout<<ans;
    return 0;
}