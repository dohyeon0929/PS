//9:30~
#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
set<int> s;
int f(int start, int end, int target){
    if(end-start<=1){
        if(v[start]<target)return -1;
        return start;
    }
    int mid = (start+end)/2;
    if(v[mid]>=target)return f(mid, end, target);
    else return f(start, mid, target);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        if(i==0){
            v.push_back(num);
        }
        else if(num<v.back()){
            v.push_back(num);
        }
        else{
            int idx = f(0,v.size(),num);
            // cout<<"idx : "<<idx<<'\n';
            if(v[idx]==num)v[idx]=num;
            else v[idx+1]=num;
        }
        // for(int i=0; i<v.size(); i++){
        // cout<<v[i]<<' ';
        // }
        // cout<<'\n';
    }    
    // cout<<'\n';
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<' ';
    // }
    cout<<n-v.size();
    return 0;
}