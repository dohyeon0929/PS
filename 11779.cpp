#define des first
#define cost second
#include <bits/stdc++.h>
using namespace std;
int n,m;
int start, End;
int dp[100001];
int city_num[100001];
vector<int> city[100001];
vector<pair<int,int>> v[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    cin>>start>>End;
    for(int i=0; i<=n; i++){
        dp[i]=123456789;
    }
    dp[start]=0;
    city[start]={};
    city_num[start]=1;
    for(int i=start; i!=End; (start<End?i++:i--)){
        // cout<<"i : "<<i<<'\n';
        for(int j=0; j<v[i].size(); j++){
            // cout<<"j : "<<j<<'\n';
            if(dp[v[i][j].des]>dp[i]+v[i][j].cost){
                dp[v[i][j].des]=dp[i]+v[i][j].cost;
                // cout<<"dp[v[i][j].des] : "<<dp[v[i][j].des]<<'\n';
                //이미 1이 들어가있음...
                // for(int k=0; k<city[i].size(); k++){
                //     city[v[i][j].des].push_back(city[i][k]);
                //     cout<<"?";
                //     cout<<city[i][k]<<' ';
                // }
                // cout<<'\n';
                city[v[i][j].des].clear();
                city[v[i][j].des].insert(city[v[i][j].des].begin(), city[i].begin(), city[i].end());
                city[v[i][j].des].push_back(i);
                // for(int k=0; k<city[v[i][j].des].size(); k++){
                //     cout<<city[v[i][j].des][k]<<' ';
                // }
                // cout<<'\n';
                city_num[v[i][j].des]=city_num[i]+1;
            }
        }
    }
    city[End].push_back(End);
    cout<<dp[End]<<'\n';
    // sort(city[End].begin(), city[End].end());
    cout<<city_num[End]<<'\n';
    for(int i=0; i<city[End].size(); i++){
        cout<<city[End][i]<<' ';
    }
    return 0;
}