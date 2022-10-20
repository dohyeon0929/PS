#define MAX 1000001
#include <bits/stdc++.h>
using namespace std;
int arr[MAX];
map<int,int> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ans=0;
    int num;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        m[num] = m[num-1]+1;
        ans = max(ans, m[num]);
    }
    cout<<n-ans;
    return 0;
}