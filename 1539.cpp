#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> p;
    list<vector<int>> li;
    // list<vector<int>>::iterator it;
    vector<list<vector<int>>*> pointers;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    li.push_front({p[0],0,0,0});
    pointers[0]=&li.front();
    for(int i=1; i<n;i++){
        for(int j=0;j<21;j++){
            int now = pow(2,j);
            if(p[i]<tree[now][0] && p[i]>tree[now-1][0]){
                li.insert(iter)
            }
        }
    }
    return 0;
}