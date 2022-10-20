#include <bits/stdc++.h>
using namespace std;
int n,m,num;
int known[51];
int ans=0;
vector<int> party[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>num; 
    int a;
    for(int i=0; i<num; i++){
        cin>>a;
        known[a]=1;
    }
    for(int i=0; i<m; i++){
        cin>>num;
        for(int j=0; j<num; j++){
            cin>>a;
            party[i].push_back(a);
        }
    }
    for(int b=0; b<m+1; b++){
        for(int i=0; i<m; i++){
            bool isTrue = 0;
            for(int j=0; j<party[i].size(); j++){
                if(known[party[i][j]]==1){
                    isTrue=1;
                }
            }
            if(isTrue){
                for(int j=0; j<party[i].size(); j++){
                    known[party[i][j]]=1;
                }
            }
            else{
                if(b==m)
                    ans+=1;
            }
        }
    }
    cout<<ans;
    return 0;
}