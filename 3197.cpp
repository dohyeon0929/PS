#include <bits/stdc++.h>
using namespace std;
char board[1502][1502];
bool check[1502][1502];
bool seed_check[1502][1502];
bool is_seed[1502][1502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int day=0;
int n,m;
bool flag=false;
queue<vector<int>> s;
vector<vector<int>> swan;
vector<vector<int>> seed;

void printBoard();

void bfs(int i, int j){
    s.push({i,j});
    vector<int> firsts = {i,j};
    while(!s.empty()){
        vector<int> cur = s.front(); s.pop();
        seed_check[i][j]=true;
        for(int k=0;k<4;k++){
            int newi=cur[0]+dx[k];
            int newj=cur[1]+dy[k];
            if(newi<=0||newj<=0||newi>n||newj>m){
                continue;
            }
            if(board[newi][newj]=='.'&&(check[newi][newj]==false||seed_check[newi][newj]==false)){
                vector<int> temp = {newi,newj};
                s.push(temp); //push가 안 되는 것 같은데...
                // cout<<"s.back()[0] : "<<s.back()[0]<<'\n';
                check[newi][newj]=true;
            }
            else if(board[newi][newj]=='X'){
                // if(cur[0]==9) cout<<"@@@cur is 9 / newi : "<<newi<<" newj : "<<newj<<'\n';
                // cout<<"melt"<<" newi : "<<newi<<" newj : "<<newj<<'\n';
                board[newi][newj]='.';
                check[newi][newj]=true;
            }
            else if(board[newi][newj]=='L'){
                if(board[i][j]=='L'){
                    flag=true;
                    break;
                }
                else{
                    vector<int> temp = {newi,newj};
                    s.push(temp); //push가 안 되는 것 같은데...
                    // cout<<"s.back()[0] : "<<s.back()[0]<<'\n';
                    check[newi][newj]=true;   
                }

            }
            // if(s.empty()&&s.front()[0]==9) cout<<"yeah s.front()[0]=9 and wigiwigiwigi"<<'\n';
        }
    }
}
void checkClear(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            check[i][j]=false;
            seed_check[i][j]=false;
        }
    }
}
void printBoard(){
    cout<<"\n\n";
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cout<<board[i][j];
        }
        cout<<"\n\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cout<<check[i][j];
        }
        cout<<'\n';
    }
    cout<<"\n\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<'a';
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cin>>board[i][j];
            if(board[i][j]=='L'){
                swan.push_back({i,j});
            }
        }
    }
    while(true){//750
        checkClear(); 10^6
        if(day==0){
            for(int i=0;i<2;i++){
                bfs(swan[i][0],swan[i][1]);
            }

            cout<<"after first swans";
            printBoard();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(board[i][j]=='.'&&check[i][j]==false){
                        seed.push_back({i,j});
                        bfs(i,j);
                    }
                }
            }
            printBoard();
            checkClear();
            // bfs(swan[0][0],swan[0][1]);
            if(flag){
                cout<<day;
                return 0;
            }
            printBoard();
        }
        else{
            int size=seed.size();
            for(int i=0;i<size;i++){
                bfs(seed[i][0],seed[i][1]);
            }
            checkClear();
            bfs(swan[0][0],swan[0][1]);
                cout<<day;
                return 0;
        }
        printBoard();
        day++;
        cout<<"day : "<<day<<'\n';
    }
    return 0;
}