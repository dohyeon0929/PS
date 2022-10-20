#include <bits/stdc++.h>
using namespace std;
int n,m;
bool arr[200001];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    q.push(n);
    q.push(0);
    int temp,now;
    while(true){
        temp=q.front();
        q.pop();
        now=q.front();
        q.pop();
        if(arr[temp]==1){
            continue;
        }
        arr[temp]=1;
        if(temp==m){
            cout<<now;
            break; 
        }
        if(temp<m){
            q.push(temp*2);
            q.push(now+1);
            q.push(temp+1);
            q.push(now+1);
        }
        if(temp>0){
            q.push(temp-1);
            q.push(now+1);
        }
    }
    return 0;
}