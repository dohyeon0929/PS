//9:23
#include <bits/stdc++.h>
using namespace std;
//+ - * /
char str[101];
int grade_in[]={0,1,2,3,5};
int grade_out[] = {0,6,2,3,5};
stack<char> s;
int code(char c);
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin>>str;
    int pointer = 0;
    s.push('$');
    while(str[pointer]!='\0'){
        int flag = 0;
        if('A'<=str[pointer]&&str[pointer]<='z'){
            cout<<str[pointer];
            pointer++;
            continue;
        }
        else{
            if(str[pointer]==')'){
                while(s.top()!='('){
                    cout<<s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(grade_in[code(s.top())]>=grade_out[code(str[pointer])]){
                    cout<<s.top();
                    s.pop();   
                }
                s.push(str[pointer]);
            }
        }
        pointer++;
    }
    while(s.top()!='$'){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
int code(char c){
    if(c=='\0'){
        return 0;
    }
    else if(c=='('){
        return 1;
    }
    else if(c=='+' || c=='-'){
        return 2;
    }
    else if(c=='*'||c=='/'){
        return 3;
    }
    else if(c==')'){
        return 4;
    }
    else return 0;
}