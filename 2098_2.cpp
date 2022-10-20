#define ll long long
#include <bits/stdc++.h>
using namespace std;
int real_ans=123456789;
int board[20][20];
int dp1[20][20];
int dp1_final[20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];   
            if(board[i][j]==0&&i!=j)board[i][j]=-1;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<board[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    ll checked[20][20];

    for(int a=1; a<=n; a++){
        
        for(int i=0; i<=n; i++){
            dp1_final[i]=0;
            for(int j=0; j<=n; j++){
                dp1[i][j]=0;
                checked[i][j]=0;
            }
        }
        cout<<"a : "<<a<<'\n';
        for(int i=1; i<=n; i++){
            if(a==i)continue;
            dp1[2][i]=board[a][i];
            checked[2][i]=1<<a | 1<<i;
            // cout<<"first checked : "<<checked[2][i]<<"\n";
            // for(int j=n; j>=1; j--){
            //     cout<<(checked[2][i]>>j&1);
            // }
            // cout<<'\n';
        }
        for(int i=3; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(a==j)continue;
                for(int k=1; k<=n; k++){
                    if(a==k){
                        // cout<<"i : "<<i<<"  j : "<<j<<"  k : "<<k<<'\n';
                        // cout<<"a==k\n";
                        continue;
                    }
                    if(j==k){
                        // cout<<"i : "<<i<<"  j : "<<j<<"  k : "<<k<<'\n';
                        // cout<<"j==k\n";
                        continue;
                    }
                    if((checked[i-1][k]>>j)&1){
                        // cout<<"i : "<<i<<"  j : "<<j<<"  k : "<<k<<'\n';
                        // cout<<"checked[i-1][k] problem\n";
                        // for(int x=n; x>=2; x--){
                        //     cout<<(checked[i-1][k]>>x&1);
                        // }
                        // cout<<'\n';
                        continue;
                    }
                    if(dp1[i-1][k]==-1)continue;
                    if(board[k][j]==-1){
                        // cout<<"i : "<<i<<"  j : "<<j<<"  k : "<<k<<'\n';
                        // cout<<"board[k][j]==-1\n";
                        continue;
                    }
                    // cout<<"real\n";
                    if(dp1[i][j]==0 || dp1[i][j]>dp1[i-1][j]+board[k][j]){
                        dp1[i][j]=dp1[i-1][k]+board[k][j];
                        checked[i][j]=checked[i-1][k]|(1<<j);
                    }
                }
                if(dp1[i][j]==0)dp1[i][j]=-1;
            }
        }
        cout<<"dp\n";
        for(int i=2; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<dp1[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
        cout<<"checked\n";
        for(int i=2; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<checked[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<"final dp\n";
        for(int i=1; i<=n; i++){
            if(a==i)continue;
            if(dp1[n][i]==-1||board[i][a]==-1)
                dp1_final[i]=123456789;
            else{
                dp1_final[i]=dp1[n][i]+board[i][a];
            }
            cout<<dp1_final[i]<<' ';
        }
        cout<<'\n';
        
        int ans = 123456789;
        for(int i=1; i<=n; i++){
            if(a==i)continue;
            ans = min(ans, dp1_final[i]);
        }
        cout<<"ans : "<<ans<<'\n';
        real_ans = min(real_ans, ans);
    }
    cout<<real_ans;
    return 0;
}