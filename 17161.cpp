#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin>>a;
    cin>>b;
    if(a.length()<=b.length()){
        for(int i=0; i<a.length(); i++){
            if(a[i]!=b[i])
                cout<<"m "<<b[i]<<'\n';
            else
                cout<<"c "<<b[i]<<'\n';
        }
        for(int i=a.length(); i<b.length(); i++){
            cout<<"a "<<b[i]<<'\n';
        }
    }
    else{
        for(int i=0; i<b.length(); i++){
            if(a[i]!=b[i])
                cout<<"m "<<b[i]<<'\n';
            else
                cout<<"c "<<b[i]<<'\n';
        }
        for(int i=b.length(); i<a.length(); i++){
            cout<<"d "<<a[i]<<'\n';
        }
    }

    return 0;
}