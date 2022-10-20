#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 100001
int arr[MAX_NUM];
int num;

int process(int st, int ed){
    // cout<<"st : "<<st<<','<<"ed : "<<ed<<'\n';
    if(ed<=st+1) {
        if(arr[st]==num){return 1;}
        else {return 0;}
    }
    int mid = (st+ed)/2;
    if(num>arr[mid]) {return process(mid+1, ed);}
    else if(num==arr[mid]) {return 1;}
    else {return process(st, mid);}
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill_n(arr,MAX_NUM,-1);
    int i,n,m;
    int marr[MAX_NUM];
    cin>>n;
    for(i=0; i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>m;
    for(i=0;i<m;i++){
        cin>>marr[i];
        num = marr[i];
        cout<<process(0,n) <<'\n';

    }
    return 0;
}
