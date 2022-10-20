#define UP true
#define DOWN false
#include <bits/stdc++.h>
using namespace std;
vector<int> v(100001);
int up[100001];
int down[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    up[0]=down[0]=1;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(v[i]>v[i-1]){
            up[i]=up[i-1]+1;
            down[i]=1;
        }
        else if(v[i]<v[i-1]){
            down[i]=down[i-1]+1;
            up[i]=1;
        }
        else{
            up[i]=up[i-1]+1;
            down[i]=down[i-1]+1;
        }
        ans = max(ans,up[i]);
        ans = max(ans,down[i]);
    } 
    cout<<ans;
    return 0;
}