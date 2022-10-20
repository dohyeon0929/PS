#include <bits/stdc++.h>
using namespace std;
set<int> s;
int arr[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    s.insert(0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> v;
    for(int i=0; i<n; i++){
        for(auto j : s){
            v.push_back(j+arr[i]);
        }
        for(auto j : v){
            s.insert(j);
        }
    }
    int cnt=0;
    for(auto i : s){
        if(cnt!=i){
            cout<<cnt;
            break;
        }
        cnt++;
    }
    return 0;
}