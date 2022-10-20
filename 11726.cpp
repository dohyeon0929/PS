#include <bits/stdc++.h>
using namespace std;
int n;
int f(int x){
    int ans=1;
    for(int i=1; i<=x; i++){
        ans*=i;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<=n; i++){
        ans+=(f(n-i)/(f(i)*f((n-i*2)))/10007;
    }
    return 0;
}