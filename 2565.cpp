#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
pairs line[101];
// set<int> graph[501];
int overlap[101][101];
// int overlap[101];
int dp[101][101];
int used[101][101][101];
int power_table[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        line[i]={a,b};
    }
    sort(line, line+n);
    //겹치는 횟수 체크 
    int total_overlap=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(line[j].second < line[i].second){
                overlap[i][j] = overlap[j][i] = 1;
                power_table[i]++; power_table[j]++;
                // graph[i].insert(j);
                // graph[j].insert(i);
                total_overlap++;
            }
        }
    }
    // cout<<"total : "<<total_overlap<<'\n';
    for(int i=0; i<n; i++){
        dp[1][i]=power_table[i];
        used[1][i][i]=1;
        if(dp[1][i]==total_overlap){
            cout<<1;
            return 0;
        }
    }
    int ans, token;
    for(int i=2; i<=n; i++){ //100
        for(int j=0; j<n; j++){ //100
            for(int k=0; k<n; k++){ //100
                if(j==k) continue;
                if(used[i-1][k][j])continue;
                int power = power_table[j];
                
                for(int l=0; l<n; l++){ //100
                    if(used[i-1][k][l] && overlap[j][l]){
                        power--;
                    }
                }
                if(dp[i-1][k]+power > dp[i][j]){
                    dp[i][j] = dp[i-1][k]+power;
                    token = k;
                }
            }
            for(int k=0; k<n; k++){
                used[i][j][k]=used[i-1][token][k];
            }
            used[i][j][j]=1;
            if(dp[i][j]>=total_overlap){
                // cout<<i<<','<<j<<'\n';
                // cout<<'\n';
                // for(int b=0; b<n; b++){
                //     for(int a=1; a<=i; a++){
                //         cout<<dp[a][b]<<' ';
                //     }
                //     cout<<'\n';
                // }
                // cout<<'\n';
                // for(int a=0; a<n; a++){
                //     if(used[i][j][a])cout<<a<<' ';
                // }
                // cout<<'\n';
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}