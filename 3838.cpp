#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int pos[2];
int token=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==1){
                if((i+j)%2==0) pos[0]++;
                else pos[1]++;
            }
            else if(board[i][j]==2){
                token=(i+j)%2;
            }
        }
    }
    if(pos[token]!=0)cout<<"Kiriya";
    else cout<<"Lena";
    return 0;
}