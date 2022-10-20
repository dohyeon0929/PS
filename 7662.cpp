#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;
char command;
int t,k,num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0; i<t; i++){
        ms.clear();
        cin>>k;
        for(int j=0; j<k; j++){
            cin>>command>>num;
            if(command=='I'){
                ms.insert(num);
            }
            else{
                if(ms.empty()){
                    continue;
                }
                else{
                    if(num==-1){
                        ms.erase(ms.begin());
                    }
                    else{
                        ms.erase(prev(ms.end()));
                    }
                }
            }
        }
        if(ms.empty())cout<<"EMPTY"<<'\n';
        else{
            cout<<*prev(ms.end())<<' '<<*ms.begin()<<'\n';
       } 
    }
    return 0;
}