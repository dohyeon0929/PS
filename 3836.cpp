#include <bits/stdc++.h>
using namespace std;
map<char, string > m = {{'a',"aespa"}, {'b',"baekjoon"},{'c',"cau"},{'d',"debug"},{'e',"edge"},
{'f',"firefox"},{'g',"golang"},{'h',"haegang"},{'i',"iu"},{'j',"java"},{'k',"kotlin"},
{'l',"lol"},{'m',"mips"},{'n',"null"},{'o',"os"},{'p',"python"},{'q',"query"},
{'r',"roka"},{'s',"solvedac"},{'t',"tod"},{'u',"unix"},{'v',"virus"},
{'w',"whale"},{'x',"xcode"},{'y',"yahoo"},{'z',"zebra"}};
vector<char> Code;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int pointer = 0;
    cin>>s;    
    while(pointer<s.length()){
        string now = m[s[pointer]];
        int now_len = now.length();
        if(now==s.substr(pointer,now_len)){
            Code.push_back(s[pointer]);
            pointer+=now_len;
        }
        else{
            cout<<"ERROR!";
            return 0;
        }
    }
    cout<<"It's HG!"<<'\n';
    for(int i=0; i<Code.size(); i++){
        cout<<Code[i];
    } 
    return 0;
}