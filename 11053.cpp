#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[1000];
pair<int,int> sorted_arr[1000];
int num[1000];
int MAX=0;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        arr[i]=sorted_arr[i]=make_pair(a,i);
        num[i]=1;
    }
    sort(sorted_arr,sorted_arr+n,compare);
    // cout<<"sorted_arr\n";
    // for(int i=0; i<n; i++){
    //     cout<<sorted_arr[i]<<' ';
    // }
    // cout<<'\n';
    int target;
    int val;
    for(int i= n-1; i>=0; i--){
        val=1;
        // cout<<"sorted_arr[i] : "<<sorted_arr[i]<<'\n';
        int pos = sorted_arr[i].second;
        // cout<<"pos : "<<pos<<'\n';
        // cout<<"arr[pos] : "<<arr[pos]<<'\n';
        for(int j=pos+1; j<n; j++){
            if(arr[j].first>sorted_arr[i].first){
                if(val<=num[j]){
                    val = num[j] + 1;
                }
            }
        }
        num[pos]=val;
        // cout<<"val : "<<val<<'\n';
        MAX = max(val,MAX);
    }
    cout<<MAX;
    return 0;
}