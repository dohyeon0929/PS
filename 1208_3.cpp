#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> v2;
map<int,int> m;
int arr[41];
vector<int> Left;
long long ans=0;
int now = 0;
int Mode=0;
void func(vector<int>& v, int idx){
    if(idx>=v.size()){
        if(Mode==0){
            m[now]+=1;
            // cout<<'?';
            return;
        }
        else{
            Left.push_back(now);
            return;
        }
   }
    func(v, idx+1);
    now+=v[idx];
    func(v,idx+1);
    now-=v[idx];
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n,s,a;
    cin>>n>>s;
    for(int i=0; i<n/2; i++){
        cin>>a;
        arr[i]=a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());
    for(int i=n/2; i<n; i++){
        cin>>a;
        arr[i]=a;
        v2.push_back(a);
    }
    sort(v2.begin(), v2.end());

    func(v2, 0);
    Mode=1;
    func(v1, 0);
    for(int i=0; i<Left.size(); i++){
        ans+=m[s-Left[i]];
    }
    if(s==0)cout<<ans-1;
    else cout<<ans;
    return 0;
}