#define INF 0x7fffffff
#include <bits/stdc++.h>
using namespace std;
int n;
int dp[3000000];
int before[3000000];
bool flag = false;
void f(int x,int num){
    if(flag)return;
    if(x>n){
        return;
    }
    else{
        int arr[]={x+1,x*2,x*3};
        for(int i=0; i<3; i++){
            if(dp[arr[i]]>num){
                dp[arr[i]]=num;
                before[arr[i]]=x;
            }
            f(arr[i],num+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fill(dp,dp+n+1,INF);
    f(1,1);
    while(!q.empty()){
        
        if(flag)return;
        if(x>n){
            return;
        }
        else{
            int arr[]={x+1,x*2,x*3};
            for(int i=0; i<3; i++){
                if(dp[arr[i]]>num){
                    dp[arr[i]]=num;
                    before[arr[i]]=x;
                }
                f(arr[i],num+1);
            }
        }
    }
    cout<<dp[n]<<'\n';
    int x=n;
    cout<<n<<' ';
    while(x!=1){
        x=before[x];
        cout<<x<<' ';
    }
    return 0;
}