#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num;
    string s;
    for(int i=0; i<n; i++){
        cin>>num;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            for(int k=0; k<num; k++){
                cout<<s[j];
            }
        }
        cout<<'\n';
    }
    return 0;
}