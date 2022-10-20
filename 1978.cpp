#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int ans=0;
    for(int i=0; i<n;i++){
        cin>>arr[i];
        bool flag=true;
        for(int j=2; j*j<=arr[i]; j++){
            if(arr[i]%j==0) {
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
        if(arr[i]==1)ans--;
    }
    cout<<ans;
    return 0;
}