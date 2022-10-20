//떠올린 후 구현 2:13~2:18
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=n; i>1; i--){
        if(arr[1]!=0)break; 
        if(i%3==0&&(arr[i/3]==0||arr[i/3]>arr[i]+1)){
            arr[i/3]=arr[i]+1;
        }
        if(i%2==0&&(arr[i/2]==0||arr[i/2]>arr[i]+1)){
            arr[i/2]=arr[i]+1;
        }
        if(arr[i-1]==0||arr[i-1]>arr[i]+1){
            arr[i-1]=arr[i]+1;
        }
    }
    cout<<arr[1];
    return 0;
}