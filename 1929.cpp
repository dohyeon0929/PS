//1:35~
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes;
    vector<bool> state(MAX+1,true);
    state[1]=false;
    int m,n;
    cin>>m>>n; 
    for(int i=2;i*i<=n;i++){
        if(!state[i])continue;
        for(int j=i*i;j<=n;j+=i){
           state[j]=false; 
        }
    }
    for(int i=m;i<=n;i++){
        if(state[i]){
            cout<<i<<'\n';
        }
    }
    return 0;
}