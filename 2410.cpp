#define MOD 1000000000
#define ll long long
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[1000001][20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<=19; i++){
        v.push_back((int)pow(2,i));
    } 
    dp[0][0]=1; 
    for(int i=0; i<n; i++){
        for(int j=0; j<=19; j++){
            for(int k=j; k<=19; k++){
                if(i+v[k]>n)break;
                dp[i+v[k]][k]+=dp[i][j];
                dp[i+v[k]][k]%=MOD;
            }
        }
    } 
    int ans=0;
    for(int i=0; i<=19; i++){
        ans += dp[n][i];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}