#define ll long long
#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int Sub[100000];
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1; i<n; i++){
        Sub[i-1]=arr[i]-arr[i-1];
    }
    ll Sum=0;
    ll Min=2000000001;
    int less_pointer=0;
    for(int i=0; i<n-1; i++){
        Sum+=Sub[i];
        if(Sum>=m){
            while(Sum>=m){
                if(i-less_pointer>0) Sum-=Sub[less_pointer++];
                else break;
            }
            if(Sum<m) Sum+=Sub[--less_pointer];
            if(Sum<Min)Min=Sum;
        }
    }
    cout<<Min;
    return 0;
}