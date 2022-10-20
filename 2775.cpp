#include <bits/stdc++.h>
using namespace std;
int arr[5];
int main(){
    int ans=0;
    for(int i=0; i<5; i++){
        cin>>arr[i];
        ans+=pow(arr[i],2);
    }
    cout<<ans%10; 
    return 0;
}