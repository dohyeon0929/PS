#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int total;
void f(int start, int mid, int end, int n){
    if(n==1){
        // cout<<start<<' '<<end<<'\n';
        ans.push_back({start,end});
        return;
    }
    f(start, end, mid, n-1);
    ans.push_back({start,end});
    f(mid, start, end, n-1);
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    total=n;
    f(1,2,3,n);
    answer = ans;
    for(auto i : answer){
        cout<<i[0]<<' '<<i[1]<<'\n';
    }
    return answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution(2);
    return 0;
}