#include <bits/stdc++.h>
using namespace std;
int garo[10][10];
int sero[10][10];
int kan[3][3][10];
int board[10][10];
int no_board[10][10][10];
bool real_flag=0;

bool Save_Check(int i, int j, int k){//10^2
    int save_board = board[i][j];
    for(int a=0; a<9; a++){
        board[i][j]=k;
        no_board[i][a][k]+=1;
        no_board[a][j][k]+=1;
    }
    bool flag=1;
    for(int a=0; a<9; a+=3){
        for(int b=0; b<9; b+=3){
            bool can=0;
            for(int c=a; c<a+3; c++){
                for(int d=b; d<b+3; d++){
                    if(board[c][d]==k||no_board[c][d][k]==0){
                        can=1;
                    }
                }
            }
            if(can==0){
                for(int a=0; a<9; a++){
                    board[i][j] = save_board;
                    no_board[i][a][k]-=1;
                    no_board[a][j][k]-=1;
                }
                return 0;
            }
        }
    }
    return 1;
}
void f(int i, int j){
    if(real_flag)return;
    if(board[i][j]!=0){
        if(i==8&&j==8){
            for(int x=0; x<9; x++){
                for(int y=0; y<9; y++){
                    cout<<board[x][y];
                }
                cout<<'\n';
            }
            real_flag=1;
            return;
        }
        if(j==8)f(i+1,0);
        else f(i, j+1);
        return;
    }
    for(int k=1; k<=9; k++){
        if(garo[i][k])continue;
        if(sero[j][k])continue;
        if(kan[i/3][j/3][k])continue;
        if(Save_Check(i,j,k)){
            board[i][j]=k;
            garo[i][k]=1;
            sero[j][k]=1;
            kan[i/3][j/3][k]=1;
            if(i==8&&j==8){
                for(int x=0; x<9; x++){
                    for(int y=0; y<9; y++){
                        cout<<board[x][y];
                    }
                    cout<<'\n';
                    real_flag=1;
                }
                return;
            }
            else{
                if(j==8)f(i+1,0);
                else f(i, j+1);
            } 
            board[i][j]=0;
            garo[i][k]=0;
            sero[j][k]=0;
            kan[i/3][j/3][k]=0;
            
        }
        for(int a=0; a<9; a++){
            no_board[i][a][k]-=1;
            no_board[a][j][k]-=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>a;
            board[i][j] = a - '0';
            garo[i][board[i][j]]=1;
            sero[j][board[i][j]]=1;
            kan[i/3][j/3][board[i][j]]=1;
            Save_Check(i,j,board[i][j]);
        }
    }
    f(0,0);

    return 0;
}