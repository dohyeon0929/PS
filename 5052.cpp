#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b){
    return a.size()<b.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, num;
    string s;
    cin>>t;
    vector<string> words;
    map<string, bool> m;
    for(int x=0; x<t; x++){
        words.clear();
        m.clear();
        cin>>num;
        for(int i=0; i<num; i++){
            cin>>s;
            words.push_back(s);
            m[s]=1;
        }
        bool Exit=false;
        sort(words.begin(), words.end(), compare);
        for(int i=0; i<num; i++){
            for(int j=1; j<words[i].size(); j++){
                string temp = words[i].substr(0,j);
                if(m[temp]){
                    Exit=true;
                }
                if(Exit)break;
            }
            if(Exit)break;
        }
        if(Exit)cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}