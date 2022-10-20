#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,b,a;
    cin>>n;
    int arr[101]; 
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cin>>b;
    int ans=0;
    for(int i=0; i<n; i++){
        if(b==arr[i])ans+=1;
    }
    cout<<ans;
    return 0;
}