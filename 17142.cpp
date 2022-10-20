#include <bits/stdc++.h>
using namespace std;
int n,m,virus_num;
int board[50][50];
bool check[50][50];
bool save_check[50][50];
bool cannotGo[50][50];
bool save_cannotGo[50][50];
int check_finish=0;
int save_check_finish=0;
int Select[50];
int ans=10000;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<pair<int,int>> virus;
vector<pair<int,int>> active_virus;
queue<pair<int,int>> bfs_queue;

void input();
void combination(int idx, int cnt);
void process();
bool isFinished();
void resetCheck();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    input();
    if(isFinished()){
        ans=0;
        cout<<ans;
        return 0;
    }
    combination(0,0);
    if(ans==10000)ans=-1;
    cout<<ans;
    return 0;
}

void input(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            check[i][j]=false;
            cannotGo[i][j]=false;
            save_cannotGo[i][j]=false;
            if(board[i][j]==1){
                cannotGo[i][j]=true;
            }
            if(board[i][j]==1||board[i][j]==2){
                check[i][j]=true;
                check_finish+=1;
            }
            if(board[i][j]==2){
                virus.push_back(make_pair(i,j));
            }
            save_check_finish=check_finish;
            save_check[i][j]=check[i][j];
            save_cannotGo[i][j]=cannotGo[i][j];
        }
    }
    for(int i=0; i<50; i++)Select[i]=false;
    virus_num = virus.size();
}
void combination(int idx, int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++){
            bfs_queue.push(active_virus[i]);
            cannotGo[active_virus[i].first][active_virus[i].second]=true;
        }

        process();
        check_finish = save_check_finish;
        for(int i=0; i<m; i++){
            cannotGo[active_virus[i].first][active_virus[i].second]=false;
        }
        //r개 선택 완료.
        resetCheck();
        return;
    };
    for(int i=idx; i<virus_num; i++){
        if(Select[i]==true)continue;
        Select[i] = true;
        active_virus.push_back(virus[i]);
        combination(i,cnt+1); //r개 중에서 cnt+1번째 선택
        Select[i]=false;
        active_virus.pop_back();
    }
}
void process(){
    int day=0;
    bfs_queue.push(make_pair(-1,-1));
    pair<int,int> save_bfs_queue_front = bfs_queue.front();

    while(!bfs_queue.empty()){
        pair<int,int> cur = bfs_queue.front(); bfs_queue.pop();
        if(cur.first==-1){
            day+=1;
            if(isFinished()&&ans>day){
                ans = day;
                while(!bfs_queue.empty()){
                    bfs_queue.pop();
                }
                return;
            }

            if(!bfs_queue.empty())bfs_queue.push(make_pair(-1,-1));
            else return;
        }
        for(int i=0; i<4; i++){
            int newi = cur.first + dx[i];
            int newj = cur.second + dy[i];
            if(newi<0||newj<0||newi>=n||newj>=n)continue;
            if(check[newi][newj]==false){
                bfs_queue.push(make_pair(newi,newj));
                check[newi][newj]=true;
                check_finish+=1;
            }
            else if(board[newi][newj]==2&&cannotGo[newi][newj]==false){
                bfs_queue.push(make_pair(newi,newj));
                cannotGo[newi][newj]=true;
            }
        }
    }
}
bool isFinished(){
    if(check_finish==n*n)return true;
    return false;
}

void resetCheck(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            check[i][j]=save_check[i][j];
            cannotGo[i][j]=save_cannotGo[i][j];
        }
    }
}