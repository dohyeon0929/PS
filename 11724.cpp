//7:05 ~ 7:41    36분 소요 
#include <bits/stdc++.h>
using namespace std;
vector<set<int>> v(1001);
bool arr[1001];
int ans=0;
void func(int i);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        v[a].insert(b);
        v[b].insert(a);
    }
    for(int i=1; i<=n; i++){
        if(arr[i]==false){
            arr[i]=true;
            for(auto it = v[i].begin(); it !=v[i].end(); it++){
                func(*it);
            }
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
void func(int i){
    if(arr[i]==false){
        arr[i]=true;
        for(auto it = v[i].begin(); it !=v[i].end(); it++){
            func(*it);
        }
    }
}