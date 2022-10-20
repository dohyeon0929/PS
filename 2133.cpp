#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[31];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[2]=3;
    dp[4]=11;
    for(int i=6; i<=30; i+=2){
        if(i%4==0){
            dp[i]=dp[i/2]*dp[i/2];
            for(int j=4; j<i; j+=4){
                if(j==2)dp[i]+=3*dp[(i/2)-(j/2)]*dp[(i/2)-(j/2)];
                else dp[i]+=2*dp[(i/2)-(j/2)]*dp[(i/2)-(j/2)];
            }
            dp[i]+=2;
        }

        else{
            dp[i]=dp[i/2-1]*dp[i/2+1];
            dp[i]+=2*dp[i/2-1];
            for(int j=4; j<i; j+=4){
                if(j==2){
                    dp[i]+=3*dp[(i/2)-(j/2)-1]*dp[(i/2)-(j/2)+1];
                    dp[i]+=3*dp[(i/2)-(j/2)-1];
                }
                else{
                    dp[i]+=2*dp[(i/2)-(j/2)-1]*dp[(i/2)-(j/2)+1];
                    dp[i]+=2*dp[(i/2)-(j/2)-1];
                }
            }
            dp[i]+=2;
        }
        
    }
    cout<<dp[n];
    return 0;
}