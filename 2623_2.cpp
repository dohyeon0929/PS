#include<bits/stdc++.h>
using namespace std;
vector<bool> checked;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b,before;
    for(int i=0; i<m; i++){
        cin>>a;
        for(int i=0; i<a; i++){
            cin>>b;
            if(i!=0){
                if(checked[before]&&checked[b]){
                    continue;
                }
                else{
                    tree[before].insert(b);
                }
            }
            before=b;
        }

    }
    return 0;
}