//253
#define ll long long
#include<bits/stdc++.h>
using namespace std;
int n;
ll arr[5000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll a;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll ans=3000000001;
    ll answer[3];
    ll start, end;
    start=0;
    end=n-1;
    ll minmin=3000000001;
    ll now;
    for(int i=0; i<n; i++){
        start=0;
        end=n-1;
        while(true){
            if(start==end)break;
            if(start==i){
                start++;
                continue;
            }
            if(end==i){
                end--;
                continue;
            }
            now = arr[start]+arr[end]+arr[i];
            if(minmin>abs(now)){
                minmin = abs(now);
                answer[0]=arr[start];
                answer[1]=arr[end];
                answer[2]=arr[i];
            }
            if(now>0){
                end--;
            }
            else if(now==0){
                break;
            }
            else{
                start++;
            }
        }
    }
    sort(answer,answer+3);
    cout<<answer[0]<<' ';
    cout<<answer[1]<<' ';
    cout<<answer[2];
    return 0;
}