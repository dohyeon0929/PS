#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0; i<s.size(); i++){
        int now = s[i]-'A';
        if(now<=17)now=now/3+3;
        else if(now==18)now=8;
        else if(now<=24)now=(now-1)/3+3;
        else now=10;
        ans+=now;
    }
    cout<<ans;
    return 0;
}