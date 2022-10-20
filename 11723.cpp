#include <bits/stdc++.h>
using namespace std;
set<int> s;
void f(string com, int m){
    if( com=="add"){
        s.insert(m);
    }
    else if( com=="remove"){
        s.erase(m);
    }
    else if( com=="check"){
        if(s.find(m)!=s.end())cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    else if( com=="toggle"){
        if(s.find(m)!=s.end())s.erase(m);
        else s.insert(m);
    }
    else if( com=="all"){
        for(int i=1; i<=20; i++){
            s.insert(i);
        }
    }
    else{
        s.clear();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>m;
    int num;
    string com;
    for(int i=0; i<m; i++){
        cin>>com;
        if(com=="all"||com=="empty")f(com,0);
        else{
            cin>>num;
            f(com,num);
        }
    }
    return 0;
}