#define ll long long
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int arr[2001];
bool dp[2001][2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    float mid;
    int left,right, mid_l, mid_r;
    for(float i=0; i<n-0.5; i+=0.5){
        mid = i;
        // cout<<mid<<'\n';
        if((int)(mid*2)%2==0){
            for(int j=0; j<n; j++){
                left= mid - j; 
                right = mid + j;
                if(left<0 || right>=n ){
                    break; 
                }
                if(arr[left]==arr[right]){
                    dp[left][right]=1;
                    // cout<<"dp["<<left<<"]["<<right<<"] : "<<dp[left][right]<<'\n';
                }
                else{
                    break;
                }
            }
        }
        else{
            mid_l = (int)(mid-0.5);
            mid_r = (int)(mid+0.5);
            // cout<<mid_l<<' '<<mid_r<<'\n';
            for(int j=0; j<n; j++){
                left= mid_l - j; 
                right = mid_r + j;
                if(left<0 || right>=n ){
                    break; 
                }
                if(arr[left]==arr[right]){
                    dp[left][right]=1;
                    // cout<<"dp["<<left<<"]["<<right<<"] : "<<dp[left][right]<<'\n';
                }
                else{
                    break;
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j])ans+=1;
        }
    }
    cout<<ans;
    // int m;
    // cin>>m;
    // int a,b;
    // for(int i=0; i<m; i++){
    //     cin>>a>>b;
    //     cout<<dp[a-1][b-1]<<'\n';
    // }
    return 0;
}