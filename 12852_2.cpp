#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int before[1000001];
int n;
void f(int x, int before_x, int num){
    if(x>n)return;
    bool flag = 0;
    if(dp[x]!=123456789)flag=1;
    if(dp[x]>num){
        before[x]=before_x;
        dp[x]=min(dp[x],num);
        // cout<<"dp["<<x<<"] : "<<dp[x]<<'\n';
        f(x*3, x, num+1);
        f(x*2, x, num+1);
        f(x+1, x, num+1);
        return;
    }
    else return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fill(dp, dp+n+1, INF);
    f(1,0,0);
    cout<<dp[n]<<'\n';
    int a=n;
    while(a!=0){
        cout<<a<<' ';
        a=before[a];
    }
    return 0;
}