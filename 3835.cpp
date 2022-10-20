#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,nxt;
set<int> g[2022]; //set 형식의 그래프 
bool nomain[2022]; //메인 박스 찾는 용도 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    nxt =n;
    int c,num,mainbox;
    for(int i=1; i<=n; i++){ //입력 받기 
        cin>>c;
        for(int j=0; j<c; j++){
            cin>>num;
            g[i].insert(num);
            nomain[num]=1;
        }
    }
    for(int i=1; i<=n; i++){ //메인박스 찾기 
        if(!nomain[i]){
            mainbox=i;
            break;
        }
    }
    queue<int> q;
    q.push(mainbox); //메인박스부터 bfs 시작 
    while(!q.empty()){
        int cur = q.front(); q.pop();
        // if(g[cur].size()>m*m){ //아예 불가능한 케이스면 바로 배제 
        //     cout<<0;
        //     return 0;
        // }
        while(g[cur].size()>m){ //서브박스 초과 시 새 박스 추가해서 수 줄이기 
            nxt++; // nxt = 새 박스 번호 
            if(nxt > n+k){
                cout<<0;
                return 0;
            }
            for(int i=0; i<m; i++){ //새 박스에 기존 서브박스들 중 m개의 상자들 담기 
                g[nxt].insert(*(g[cur].begin()));
                g[cur].erase(g[cur].begin());
            }
            g[cur].insert(nxt); //새로 추가한 박스를 그래프에 넣어주기 
        }
        for(auto i : g[cur]){
            q.push(i);
        }
    }
    
    cout<<1<<'\n';
    cout<<nxt - n<<'\n';
    for(int i=1; i<=nxt; i++){
        cout<<g[i].size()<<' ';
        for(auto j : g[i]){
            cout<<j<<' ';
        }    
        cout<<'\n';
    }
    return 0;
}