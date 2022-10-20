#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1000001];
int before[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dp[0]=123456789;
    dp[1]=0;
    for(int i=2; i<=n; i++){
        int a, b, c;
        a=b=c=0; 
        a=i-1;
        if(i%2==0)b=i/2;
        if(i%3==0)c=i/3;
        if(dp[a]>dp[b]){
            dp[i]=dp[b]+1; 
            before[i]=b;
        }
        else{
            dp[i]=dp[a]+1;
            before[i]=a;
        }
        if(dp[i]>dp[c]){
            dp[i]=dp[c]+1;
            before[i]=c;
        }
        // cout<<"dp["<<i<<"] : "<<dp[i]<<'\n';
    }
    cout<<dp[n]<<'\n';
    int a=n;
    while(a!=0){
        cout<<a<<' ';
        a=before[a];
    }
    return 0;
}