#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=1; true; i++){
        int num=i; 
        int num2 = n;
        // bool last = false;
        // bool token = false;
        while(num>0 && num2>=0){
            auto tmp = lower_bound(arr, arr+num2, num);
            // if(i==56 && num2==1)
            // cout<<*lower_bound(arr, arr+0, 2)<<'\n';
            // if(num2==1)tmp=arr;
            // cout<<tmp-arr<<'\n';
            // if(tmp - arr == 0) last = true;
            // if(i==56 && num2==1)cout<<*tmp<<'\n';
            if(tmp-arr>=num2)tmp=prev(tmp);
            else if(*tmp!=num)tmp = prev(tmp);
            // else token=true;
            // if(i==56 && num2==1)cout<<*tmp<<'\n';
            num-=*tmp;
            // if(token){
            //     tmp=prev(tmp);
            //     token = false;
            // }
            num2 = tmp - arr ;
            // cout<<"i : "<<i<<" num : "<<num<<" num2 : "<<num2<<'\n';
            // if(last)break;
        } 
        if(num<0){
            cout<<i;
            return 0;
        }
        else if(num>0 &&num2==0){
            cout<<i;
            return 0;
        }
    }
    return 0;
}