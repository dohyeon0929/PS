// 1:01~
#include <bits/stdc++.h>
using namespace std;
vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<string> words;
    words = split(s,'-');
    int ans=0, now, num;
    bool first = true;
    for(auto i : words){
        if(first){
            stringstream stream(i);
            while(stream>>num){
                ans+=num;
            }
            first=false;
        }
        else{
            now=0;
            stringstream stream(i);
            while(stream>>num){
                now+=num;
            }
            ans-=now;
        }
    }
    cout<<ans;
    return 0;
}