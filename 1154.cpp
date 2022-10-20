#include <bits/stdc++.h>
using namespace std;
bool known[1001][1001];
vector<int> teamA;
vector<int> teamB;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    cin>>n;
    while(true){
        cin>>a>>b;
        if(a==-1&&b==-1)break;        
        known[a][b]=1;
        known[b][a]=1;
    }
    teamA.push_back(1);
    for(int x=2; x<=n; x++){
        bool flag=0;
        for(int i=0; i<teamA.size(); i++){//teamA 되나? 
            if(known[teamA[i]][x])continue;
            else{
                flag = 1;
                break;
            }
        }
        if(flag){//teamA 안 되면 
            bool flag2=0;
            for(int i=0; i<teamB.size(); i++){
                if(known[teamB[i]][x])continue;
                else{
                    flag2 = 1;
                    break;
                }
            }   
            if(flag2){//teamB 안 되나? 
                cout<<-1;
                return 0;
            }
            else{//teamB 가능 . 
                teamB.push_back(x);
            }
        }
        else{//teamA 된다는 뜻 
            teamA.push_back(x);
        }
        for(int i=0; i<teamA.size(); i++){
            cout<<teamA[i]<<' ';
        }
        cout<<'\n';
        for(int i=0; i<teamB.size(); i++){
            cout<<teamB[i]<<' ';
        }
        cout<<'\n';
 
    }

    cout<<1<<'\n';
    for(int i=0; i<teamA.size(); i++){
        cout<<teamA[i]<<' ';
    }
    cout<<-1<<'\n';
    for(int i=0; i<teamB.size(); i++){
        cout<<teamB[i]<<' ';
    }
    cout<<-1;
    return 0;
}