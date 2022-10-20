#include <bits/stdc++.h>
using namespace std;
#define I 0
#define J 1
int day=0;
char board[1502][1502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
vector<vector<int>> swan;
vector<vector<int>> v;
vector<vector<int>> temp;
bool check[1502][1502];

bool nearPoint(int i, int j);
void melt();
bool isLinked();


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]=='L') swan.push_back({i,j});
            check[i][j]=false;
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='X'&&nearPoint(i,j)){
                v.push_back({i,j});
            }
        }
    }
    while(true){
        melt();
        if(isLinked()){
            cout<<day;
            return 0;
        }
        day+=1;
    }
    return 0;
}

bool nearPoint(int i, int j){
    for(int k=0; k<4; k++){
        if(board[i+dx[k]][j+dy[k]]=='.') return true;
    }
    return false;
}


void melt(){
    vector<int> newnew;
    for(auto cur:v){
        board[cur[I]][cur[J]]='.'; 
        for(int j=0;j<4; j++){
            newnew = {cur[I]+dx, cur[J]+dy};
            if(board[newnew[I]][newnew[J]]=='X'){
                temp.push_back({newnew[I],newnew[J]});
            }
        }
    }
    v.clear();
    while(temp.empty()){
        v.push_back(temp.back());
        temp.pop_back();
    }
    temp.clear();
}

bool isLinked(){
    queue<vector<int>> q;
    q.push(swan[0]);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j]=false;
        }
    }
    while(!q.empty()){
        vector<int> cur = q.front(); q.pop();
        for(int i=0;i<4; i++){
            int newi = cur[I];
            int newj = cur[J];
            if(board[newi][newj]=='.'&&check[newi][newj]==false){
                q.push({newi,newj});
                check[newi][newj]=true;
            }
            if(board[newi][newj]=='L'){
                return true;
            }
        }
    }
    return false;
}