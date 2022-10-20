#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> t[1001];
bool checked[1001];
int n,m,Start,End;
int min_cost=123456789;
int now_cost=0;
int min_city_num;
int now_city_num=1;
vector<int> now_city_stack;
vector<int> ans;
void dfs(int start);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        t[a].push_back({b,c});
    }
    cin>>Start>>End;
    now_city_stack.push_back(Start);
    dfs(Start);

    cout<<min_cost<<'\n';
    cout<<min_city_num<<'\n';
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
void dfs(int start){
    checked[start]=1;
    for(auto iter : t[start]){
        // cout<<"iter.first : "<<iter.first<<'\n';
        if(iter.first!=End){
            if(checked[iter.first]!=1){
                checked[iter.first]=1;
                now_city_stack.push_back(iter.first);
                now_cost+=iter.second;
                now_city_num++;

                dfs(iter.first);

                checked[iter.first]=0;
                now_city_stack.pop_back();
                now_cost-=iter.second;
                now_city_num--;
            }
        }
        else{
            now_cost+=iter.second;
            now_city_num++;
            // cout<<"now_cost : "<<now_cost<<'\n';
            // cout<<"now_city_num : "<<now_city_num<<'\n';
            if(min_cost>now_cost){
                min_cost = now_cost;
                min_city_num = now_city_num;
                ans.clear();
                for(int i=0; i<now_city_stack.size(); i++){
                    ans.push_back(now_city_stack[i]);
                    // cout<<"ans <-- : "<<ans[i]<<'\n';
                }
                ans.push_back(End);
            }

            now_cost-=iter.second;
            now_city_num--;
        }
    }
    checked[start]=0;
}