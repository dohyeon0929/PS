#include <bits/stdc++.h>
using namespace std;
int arr[200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int MAX=0;
    char ans;
    bool token = false;
    string s;
    cin>>s;
    memset(arr,0,sizeof(arr));
    for(int i=0; i<s.size(); i++){
        if(s[i]>=97)s[i]-=32;
        arr[s[i]] +=1;
    }
    for(int i=65; i<=122; i++){
        if(MAX<arr[i]){
            MAX = arr[i];
            ans = (char)i;
        }
        else if(MAX == arr[i]){
            ans='?';
        }
    }
    cout<<ans;
    return 0;
}