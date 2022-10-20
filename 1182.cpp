#include <bits/stdc++.h>
using namespace std;
int arr[21];
int ans=0;
int real_ans=0;
int n,m;
int zero_count=0;
void f(int idx, bool i){
    // cout<<"idx : "<<idx<<'\n';
    if(i){
        ans+=arr[idx];
    }
    else{
        zero_count+=1;
    }
    if(idx!=n-1){
        for(int j=0; j<2; j++){
            f(idx+1, j);
        }
    }
    else{
        if(ans==m && zero_count!=n){
            // cout<<"!!!\n";
            real_ans+=1;
        }
    }
    if(i){
        ans-=arr[idx];
    }
    else{
        zero_count-=1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<2; i++){
        f(0,i);
    }
    cout<<real_ans;
    return 0;
}