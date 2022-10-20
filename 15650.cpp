#include <bits/stdc++.h>
using namespace std;
int n,m;
int selected[10];
vector<int> v;
void f(int x, int num){
    if(num==m){
        for(int i=0; i<num; i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=x+1; i<=n; i++){
        v.push_back(i);
        selected[i]=1;
        f(i,num+1);
        v.pop_back();
        selected[i]=0;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        v.push_back(i);
        selected[i]=1;
        f(i,1);
        v.pop_back();
        selected[i]=0;
    }
    return 0;
}
