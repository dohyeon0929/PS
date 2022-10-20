#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<string, int> h;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; 
    string name;
    string command;
    string enter = "enter";
    int c = 0;
    for(int i=0; i<n; i++){
        cin>>name;
        cin>>command;
        if(command.compare(enter)==0){
            h[name] = 1;
        }
        else{
            h.erase(name);
        }
    }
    vector<string> v;
    for(auto i : h){
        if(i.second)
            v.push_back(i.first);
    }
    sort(v.begin(), v.end(), greater<string>());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}