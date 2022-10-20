#include <bits/stdc++.h>
using namespace std;
bool compare1(string a, string b){//??가 뒤에 
    if(a.compare(b)>=0)return true;
    else return false;
}
bool compare2(string a, string b){//??가 앞에 
    if(a.reverse.compare(b.reverse)>=0)return true;
    else return false;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<int>v1 = sort(words.begin(), words.end(), compare1);
    vector<int>v2 = sort(words.begin(), words.end(), compare2);
    for(auto q : queries){
        if(q[0]=='?'){
            int q_size = q.rfind('?')+1;
            int q_idx=q.size()-q.rfind('?')+1;
            q=s
        }
        else{

        }
    }
    return answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}