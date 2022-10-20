#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int now=arr[0];
    if(now!=1){
        cout<<1;
        return 0;
    }
    for(int i=1; i<n; i++){
        if(arr[i]>now+1){
            cout<<now+1;
            return 0;
        }
        else{
            now+=arr[i];
        }
    }
    cout<<now+1;
    return 0;

}