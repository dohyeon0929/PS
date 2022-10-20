#include <bits/stdc++.h>
using namespace std;
int arr[100];
multiset<int> s;
bool compare(int a, int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        s.insert(num);
    }
    sort(arr, arr+n, compare);
    int ans=0;
    int j=0;
    for(auto i : s){
        ans+=i*arr[j];
        j++;
    }
    cout<<ans;
    return 0;
}