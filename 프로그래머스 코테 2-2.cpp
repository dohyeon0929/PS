#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
map<string,int> m;
vector<int> solution(string msg) {
    int cnt=26;
    vector<int> answer;
    for(char i = 'A'; i<='Z'; i++){
        m[i]=i-'A'+1;
    }
    while(msg.size()==0){
        string s;
        int save;
        for(int i=1; i<=msg.size(); i++){
            
            s=msg.substr(0,i);
            if(m[i]==0){
                answer.push_back(save);
                m[i]==++cnt;
                msg = msg.substr(i);
            }
            else{
                save = m[i];
            }
        }
    } 
    for(auto i : answer){
        cout<<i<<' ';
    }
    return answer;
}

int main(){
    solution(KAKAO);
    return 0;
}