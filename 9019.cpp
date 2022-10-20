//7:50~
#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int a,b;
string strb;
int main(){
    int n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        itoa(strb, b, 10);
        func(a,0)
    }
    return 0;
}
func(int a,int step){
    int aD = a*2;
    string strAD;
    itoa(strAD, aD, 10);
    v.push('D');
    if(!canTurn(strAD)){
        func(aD, step+1);
    }
    else{
        keepAns(aD, step)
    }
    v.pop();
}

bool canTurn(string s){
    int newj;
    bool flag = false;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            newj = j%4;
            if(strb[i]!=s[newj]){
                break;
            }else{
                if(j==3){
                    if(i==)
                    return true;
                }
            }
        }
    }
    return false;
}

void keepAns(int aa, int step){


}