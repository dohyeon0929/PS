#define MAX 1000000
#define MOD 1000000009
#include <bits/stdc++.h>
using namespace std;
int arr[MAX+4];
int dp[MAX+4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    dp[0]=1;
    for(int i=0; i<=MAX; i++){
        for(int j=1; j<=3; j++){
            dp[i+j]+=dp[i];
            dp[i+j]%=MOD;
        }
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}