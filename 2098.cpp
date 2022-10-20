#include<bits/stdc++.h>
using namespace std;
int board[17][17];
int n;
int list_prev[17];
int list_next[17];
vector<int> now={1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
        }
    }
    int real_ans = 123456789;
    int temp;
    // for(int abc=1; abc<=n; abc++){
        int ans=0;
        vector<int> now={1};///abc였음 
        int count=2;
        for(int i=2; i<=n; i++){//i=1이었음 
            // if(abc==i)continue;
            // cout<<"i : "<<i<<'\n';
            int save_j;
            int minmin=123456789;
            for(int j=0; j<i; j++){//i인가 count인가 
                if(i==1)continue;
                // cout<<"j : "<<j<<'\n';
                if(j-1==-1)list_prev[i]=0;
                else list_prev[i]=now[j-1];

                if(j==now.size())list_next[i]=0;
                else list_next[i]=now[j];

                if(j-1==-1){
                    if(board[i][list_next[i]]==0){
                        continue;
                    }
                }
                else if(j==now.size()){
                    if(board[list_prev[i]][i]==0){
                        continue;
                    }
                }
                else{
                    if(board[list_prev[i]][i]==0||board[i][list_next[i]]==0){
                        continue;
                    }
                }
                // cout<<"now\n";
                // for(int x=0; x<now.size(); x++){
                //     cout<<now[x]<<' ';
                // }
                // cout<<'\n';

                temp=0;
                // cout<<"i : "<<i<<'\n';
                bool flagg=0;
                for(int k=0; k<count-1; k++){
                    // cout<<"k : "<<k<<"  j : "<<j<<'\n';
                    if(j==k){
                        if(board[i][list_next[i]]==0)flagg=1;
                        temp+=board[i][list_next[i]];
                        // cout<<"temp : "<<temp<<'\n';
                    }
                    else if(j-1==k){
                        if(board[list_prev[i]][i]==0)flagg=1;
                        temp+=board[list_prev[i]][i];
                        // cout<<"temp : "<<temp<<'\n';
                    }
                    else{
                        if(j<k){
                            if(board[now[k-1]][now[k]]==0)flagg=1;
                            temp+=board[now[k-1]][now[k]];
                        }
                        else {
                            if(board[now[k]][now[k+1]]==0)flagg=1;
                            temp+=board[now[k]][now[k+1]];
                        }
                    }
                    // cout<<"temp : "<<temp<<'\n';
                }
                // if(flagg)continue;
                // cout<<"count : "<<count<<"  n : "<<n<<'\n';
                if(count==n){
                    if(j==0){
                        if(board[now[n-2]][i]==0)flagg=1;
                        temp+=board[now[n-2]][i];
                    }
                    else if(j==n-1){
                        if(board[i][now[0]]==0)flagg=1;
                        temp+=board[i][now[0]];
                    }
                    else{
                        if(board[now[n-2]][now[0]]==0)flagg=1;
                        temp+=board[now[n-2]][now[0]];
                    }
                    // cout<<"final temp : "<<temp<<'\n';
                }
                // if(count==n)
                //     cout<<"final temp : "<<temp<<'\n';
                if(minmin>temp){
                    if(flagg)continue;
                    minmin = temp;
                    // cout<<"minmin : "<<minmin<<'\n';
                    save_j = j;
                }
                
    
            }
            // int temp_ans=minmin;
            vector<int> vvv;
            for(int j=0; j<save_j; j++){
                vvv.push_back(now[j]);
            }
            vvv.push_back(i);
            for(int j=save_j; j<now.size(); j++){
                vvv.push_back(now[j]);
            }
            now.resize(count++);
            copy(vvv.begin(), vvv.end(),now.begin());

            // if(flagg)continue;
            ans=minmin;
        }
        real_ans = min(real_ans, ans);
    // }
    cout<<real_ans;
    return 0;
}