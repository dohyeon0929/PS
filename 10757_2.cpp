#include <bits/stdc++.h>
using namespace std;
char a[10001];
char b[10001];
char c[10001];
int x,y,i,u;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    x=y=i=u=0;
    while(true){ //a와 b의 자릿수 구하기
        if(a[i])x++;
        if(b[i])y++;
        if(!(a[i]+b[i]))break;
        i++;
    }
    c[(x>y?x:y)]=0;
    while(x+y){
        i=0;
        if(x) i=a[--x]-'0';
        if(y) i+=b[--y]-'0';
        i+=u;
        u=i/10;
        c[(x>y?x:y)]=i%10 + '0';
    }
    if(u)cout<<u;
    cout<<c;
    return 0;
}