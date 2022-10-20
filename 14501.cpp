#include <bits/stdc++.h>
using namespace std;
int day[17], pay[17], dp[100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>day[i]>>pay[i];
    }
    for(int i=1; i<=n+1; i++){
        dp[i] = max(dp[i], dp[i-1]);
        if(i+day[i]<=n+1)
            dp[i+day[i]] = max(dp[i+day[i]], dp[i]+pay[i]);
    }
    cout<<dp[n+1];
    return 0;
}