#include <bits/stdc++.h>
using namespace std;
vector<int> arr1;
vector<int> arr2;
int dp[2022][2022];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        arr1.push_back(num);
    }
    for(int i=0; i<n; i++){
        cin>>num;
        arr2.push_back(num);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]);
            if(arr1[i]>arr2[j]){
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + arr2[j]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}