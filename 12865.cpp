#include <bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int> arr_k[100000];
int arr[10000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int a,b;
    for(int i=0; i<n; i++){
        arr_k[i]=0x7fffffff;
    }
    for(int i=0; i<10000000; i++){
        arr[k]=0x7fffffff;
    }
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr_k[i]={a,b};
    }
    int wsum;
    int vsum;
    for(int i=0; i<n; i++){
        vsum=wsum=0;
        for(int j=i; j<n; j++){
            wsum+=arr_k[j].first;
            
            arr[wsum] = min(arr[wsum],  )
        }
    }
    return 0;
}