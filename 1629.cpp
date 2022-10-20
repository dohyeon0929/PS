//8:21
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int a,b,c;
ll ans=1;
ll arr[32];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    a%=c;
    arr[0]=a%c;
    for(int i=1; i<31; i++){
        arr[i] = ((arr[i-1])*(arr[i-1]))%c;
    }
    for(int i=30; i>=0; i--){
        if((b>>i)&1){
            ans*=arr[i];
            ans%=c;
        }
    }
    cout<<ans;
    return 0;
}