#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);	   

    int top1=0, top2=0;
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n+m);
    c.clear();
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    bool flag=false;
    while(top1<n && top2<m){
        if(a[top1]<=b[top2]){
            c.push_back(a[top1++]);
        }
        else{
            c.push_back(b[top2++]);
        }
        if(top1==n) flag=true;
    }
    if(flag){
        for(int i=top2; i<m;i++){
            c.push_back(b[top2++]);
        }
    }
    else{
        for(int i=top1;i<n; i++){
            c.push_back(a[top1++]);
        }
    }
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<' ';
    }
    return 0;
}