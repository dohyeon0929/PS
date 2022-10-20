#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num=0;
    int token;
    for(int i=1; i<=1000; i++){
        num+=i;
        if(num>n){
            token = i-1;
            break;
        }
    }
    if(token%2!=0){
        cout<<0;
    }
    else{
        cout<<num-n;
    }
    return 0;
}