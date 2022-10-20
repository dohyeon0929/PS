#include <bits/stdc++.h>
using namespace std; 
int n;
int ans=0;
vector<int> v;
vector<int> sum;
int main(){
    cin>>n;
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    sum.push_back(v[0]);
    for(int i=0; i<=n-1; i++){
        ans+=sum[i];
        if(i==n-1)break;
        sum.push_back(sum[i]+v[i+1]);
    }
    cout<<ans;
    return 0;
}