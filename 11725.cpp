#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int parent[100001];
    int floor[100001];//작을수록 파워랭킹 업
    // for(int i=1; i<=n; i++){
    //     parent[i]=floor[i]=0;
    // }
    parent[1]=1;
    floor[1]=1;
    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        if(floor[a]!=0||floor[b]!=0){
            if(floor[a]==0) {
                floor[a]=floor[b]+1;
                parent[a]=b;
            }
            else {
                floor[b]=floor[a]+1;
                parent[b]=a;
            }
        }
        else{
            
        }



        if(floor[a]<floor[b]){
            parent[b]=a;
            floor[b]=floor[a]+1;
        } 
        else{
            parent[a]=b;
            floor[a]=floor[b]+1;
        }
    }
    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
    return 0;
}