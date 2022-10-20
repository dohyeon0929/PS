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
    int line_count=0;
    vector<string> words;
    // while(cin>>s){
    while(getline(cin,s)){
        string ss;
        stringstream stream(s);
        while(stream>>ss){
            if(ss=="<br>"){
                cout<<"\n";
                line_count=0;
            }
            else if(ss=="<hr>"){
                if(line_count==0){
                    for(int i=0;i<80;i++)cout<<'-';
                    cout<<'\n';
                    line_count=0;
                }
                else{
                    cout<<'\n';
                    for(int i=0;i<80;i++)cout<<'-';
                    cout<<'\n';
                    line_count=0;
                }
            }
            else{
                if(line_count==0){
                    cout<<ss;
                    line_count=ss.size();
                }
                else{
                    if(line_count+ss.size()+1<=80){
                        cout<<' '<<ss;
                        line_count+=ss.size()+1;
                    }
                    else{
                        line_count=0;
                        cout<<'\n'<<ss;
                        line_count=ss.size();
                    }
                }
            }
        }
    }
    cout<<'\n';
    return 0;
}