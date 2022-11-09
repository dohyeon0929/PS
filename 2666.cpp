#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int dp[21][2][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r, k;
    cin>>n>>l>>r>>k;
    for(int i=0; i<=20; i++){
        for(int j=0; j<2; j++){
            dp[i][j][2]=INF;
        }
    }
    //몇 번째 질문, l/r중 어디서 가져왔는지, l/r위치랑 값
    dp[0][0][2]=dp[0][1][2]=0;
    dp[0][0][0]=dp[0][1][0]=l;
    dp[0][0][1]=dp[0][1][1]=r;
    
    int num;
    for(int i=1; i<=k; i++){
        cin>>num;
        for(int j=0; j<2; j++){
            for(int m=0; m<2; m++){
                if(abs(num-dp[i-1][m][j])+dp[i-1][m][2]<dp[i][j][2]){
                    dp[i][j][2]=dp[i-1][m][2]+abs(num-dp[i-1][m][j]);
                    dp[i][j][j]=num;
                    dp[i][j][(j+1)%2]=dp[i-1][m][(j+1)%2];
                }
            }
        }
    }
    for(int j=0; j<2; j++){
        for(int i=0; i<=k; i++){
            cout<<dp[i][j][2]<<' ';
        }
        cout<<'\n';
    }
    cout<<min(dp[k][0][2], dp[k][1][2]);
    return 0;
}