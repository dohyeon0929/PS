#include <bits/stdc++.h>
using namespace std;
int dp_line[10000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    //테이블이라길래 원순열인 줄;;
    //처음과 끝이 악수를 할 때 vs 안 할 때
    dp_line[0]=1;dp_line[1]=1; dp_line[2]=2; 
    int ans;
    for(int i=3; i<=n; i++){
        if(i%2==0){
            dp_line[i] += dp_line[i/2]*dp_line[i/2];
            dp_line[i] += dp_line[i/2-1]*dp_line[i/2-1];
        }
        else{
            dp_line[i] += dp_line[i/2+1]*dp_line[i/2];
            dp_line[i] += dp_line[i/2]*dp_line[i/2-1];
        }
        dp_line[i]%=10;
    }
    cout<<dp_line[n];
    //테이블이라길래 원순열인 줄;;
    // cout<<(dp_line[n] + dp_line[n-2])%10;
    return 0;
}