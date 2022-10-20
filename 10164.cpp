#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp1[20][20], dp2[20][20];
ll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,k;
    cin>>N>>M>>k;
    int n,m, ans=1;
    if(k!=0){
        n = k/M+1; 
        m = k%M;
        if(m==0){
            m=M;
            n--;
        }
        dp1[0][1]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp1[i][j]=dp1[i-1][j]+dp1[i][j-1];
                // cout<<dp1[i][j]<<' ';
            }
            // cout<<'\n';
        } 
        ans = dp1[n][m];
        n = N-n+1; m = M-m+1;
    }
    else{
        n=N; m=M;
    }
    // cout<<n<<','<<m<<'\n';
    dp2[0][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp2[i][j]=dp2[i-1][j]+dp2[i][j-1];
        }
    } 
    // cout<<"ans : "<<ans<<'\n';
    // cout<<"dp2 : "<<dp2[m][m]<<'\n';
    cout<<ans * dp2[n][m];
    return 0;
}