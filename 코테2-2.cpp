#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
map<string,int> m;
vector<int> solution(string msg) {
    int cnt=26;
    vector<int> answer;
    for(char i = 'A'; i<='Z'; i++){
        string s = "";
        s.push_back(i);
        m[s]=i-'A'+1;
    }
    // cout<<m["A"];
    while(msg.size()!=1){
        // cout<<'?';
        string s;
        int Save;
        while(true){
            if(msg.size()==1)break;
            int i=1;
            s=msg.substr(0,i);
            // cout<<s<<' ';
            if(m[s]==0){
                answer.push_back(Save);
                m[s]==++cnt;
                cout<<"s : "<<s<<' ';
                // cout<<"Save : "<<Save<<'\n';
                s.pop_back();
                msg = msg.substr(i-1);
                // cout<<msg<<'\n';
            }
            else{
                
                Save = m[s];
                cout<<"save s:"<<s<<'\n';
            }
        }
    } 
    answer.push_back(m[msg]);
    for(auto i : answer){
        cout<<i<<' ';
    }
    return answer;
}

int main(){
    solution("KAKAO");
    return 0;
}