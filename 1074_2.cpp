#define ll unsigned long long
#include <bits/stdc++.h>
using namespace std;
int n,r,c;
int x=0;
int y=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>c; 
    for(int i = n-1; i>=0; i--){
        if((r>>i)&1){
            y+=(1<<i)*(1<<(i+1));
        }
    }
    for(int i = n-1; i>=0; i--){
        if((c>>i)&1){
            x+=(1<<i)*(1<<i);
        }
    }
    cout<<x+y;
    return 0;
}