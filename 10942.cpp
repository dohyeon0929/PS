#include<bits/stdc++.h>
using namespace std;
int arr[2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cin>>m; 
    int start, end;
    int mid;
    for(int i=0; i<m; i++){ //10^6
        cin>>start>>end;
        mid = (end-start)/2;
        bool flag=1;
        for(int j=0; j<=mid; j++){ //10^3
            if(arr[start+j]==arr[end-j])continue;
            else{
                flag= 0;
                break;
            }
        }
        if(flag)cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}