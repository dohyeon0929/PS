#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        s.insert(num);
    }
    int ans=0;
    while(s.size()>1){
        int a = *(s.begin());    
        s.erase(s.begin());
        int b = *(s.begin());    
        s.erase(s.begin());
        ans+=a+b;
        s.insert(a+b);
    }
    cout<<ans;
    return 0;
}