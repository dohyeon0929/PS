#define M first
#define V second
#include <bits/stdc++.h>
using namespace std;
int n,m;
multiset<pair<int,int>> arr;
int bag[300000];
int dp[]
int ans=0;
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
    cin>>n>>k;
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr.insert({a,b});
    }
    for(int i=0; i<m; i++){
        cin>>bag[i];
    }
    sort(bag,bag+k);
    for(int i=0; i<k; i++){
        int mmm=0;
        int val=0;
        int save_j=-1;
        for(auto j=arr.begin(); j!=arr.end(); j++){
            if(*j.M<=bag[i]){
                if(*j.V>val){
                    mmm=*j.M;
                    val=*j.V;
                }
            }
        }
        if(save_j==-1)continue;
        ans+=arr[j].V;
        arr[]

    }
    return 0;

}