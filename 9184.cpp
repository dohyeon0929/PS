#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];

int f(int a, int b, int c){
    if(dp[a][b][c]!=INF)return dp[a][b][c];
    if(a<=50 || b<=50 || c<=50){
        dp[a][b][c]=1;
    }
    else if(a>70 || b>70 || c>70) {
        dp[a][b][c]=f(70,70,70);
    }
    else if(a<b && b<c){
        dp[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
    } 
    else {
        dp[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
    }
    return dp[a][b][c];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            for(int k=0; k<=100; k++){
                dp[i][j][k]=INF;
            }
        }
    }
    int a,b,c;
    while(true){
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1) break;
        a+=50; b+=50; c+=50;
        cout<<"w("<<a-50<<", "<<b-50<<", "<<c-50<<") = "<<f(a,b,c)<<'\n';
    }
    return 0;
}