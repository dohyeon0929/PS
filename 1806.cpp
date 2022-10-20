//1253
#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int n,s;
int st=0;
int en=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int Sum=0;
    int Min=0x7fffffff;
    for(st=0; st<n; st++){
        while(en<=n&&Sum<s)Sum+=arr[en++];
        if(en>n)break;
        Sum-=arr[st];
        Min = min(Min,en-st);
        // cout<<"min : "<<Min<<"  en, st : "<<en<<' '<<st<<'\n';
    }
    if(Min==0x7fffffff)Min=0;
    cout<<Min;
    return 0;
}