#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001
int n,m;
int arr[2*MAX];
bool check[2*MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        arr[MAX+num]+=1;
        check[MAX+num]=true;
    }
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>num;
        if(check[MAX+num]){
            cout<<arr[MAX+num]<<' ';
        }
        else{
            cout<<0<<' ';
        }
    } 
    return 0;
}