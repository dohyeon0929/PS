#include <bits/stdc++.h>
using namespace std;
int n, r;
int board[20][20];
int Select[20];
bool used[20];
int sum=0;
int ans=10000000;
vector<int> v;
void combination(int idx, int cnt);
void process();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    r=n/2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            sum+=board[i][j];
        }
    }
    combination(0,0);
    cout<<ans;
    return 0;
}
void combination(int idx, int cnt){
    if(cnt==r){
        process();
        return;
    }
    for(int i=0; i<n; i++){
        if(Select[i]==true){
            continue;
        }
        Select[i]=true;
        v.push_back(i);
        combination(i, cnt+1);
        Select[i]=false;
        v.pop_back(); 
    }
}
void process(){//100
    int point=0;
    int _point=0;
    vector<int> reverseV;
    for(int i=0; i<n; i++){
        used[i]=false;
    }
    for(int i=0; i<r; i++){
        used[v[i]]=true;
    }
    for(int i=0; i<n; i++){
        if(used[i]==false)reverseV.push_back(i);
    }
    
    for(int i=0; i<r; i++){
        for(int j=i+1; j<r; j++){
            point+=(board[v[i]][v[j]]+board[v[j]][v[i]]);
            _point+=(board[reverseV[i]][reverseV[j]]+board[reverseV[j]][reverseV[i]]);
        }
    }
    int finally = abs(point - _point);
    if(ans > finally)ans=finally;
    reverseV.clear();
}