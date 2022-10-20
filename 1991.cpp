#include <bits/stdc++.h>
using namespace std;
int n;
char arr[300][2];
void f1(int x){
    cout<<(char)x;
    if(arr[x][0]!=0) f1(arr[x][0]);
    if(arr[x][1]!=0) f1(arr[x][1]);
}
void f2(int x){
    if(arr[x][0]!=0) f2(arr[x][0]);
    cout<<(char)x;
    if(arr[x][1]!=0) f2(arr[x][1]);
}
void f3(int x){
    if(arr[x][0]!=0) f3(arr[x][0]);
    if(arr[x][1]!=0) f3(arr[x][1]);
    cout<<(char)x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; 
    char a,b,c;
    int start;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        if(i==0)start = (int)a;
        if(b!='.') arr[(int)a][0]=b;
        if(c!='.') arr[(int)a][1]=c;
    }
    f1(start);
    cout<<'\n';
    f2(start);
    cout<<'\n';
    f3(start);
    cout<<'\n';
    return 0;
}