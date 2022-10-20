#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ans=0;
int m;
int board[12][12];
int no[12][12];
// set<int> s[12];
void print(){
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout<<no[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
}
void f(int n){
    if(n==m){
        // print();
        ans+=1;
        return;
    }
    // print();
    for(int i=0; i<m; i++){
        if(no[n][i]>0)continue;

        int temp_y=n+1;
        int temp_x=i+1;
        while(temp_x>=0 && temp_x<m && temp_y<m){
            no[temp_y++][temp_x++]+=1;
        }
        temp_y=n+1;
        temp_x=i-1;
        while(temp_x>=0 && temp_x<m && temp_y<m){
            no[temp_y++][temp_x--]+=1;
        }
        for(int j = n+1; j<m; j++){
            no[j][i]+=1;
        }
        board[n][i]=1;
        f(n+1);

        board[n][i]=0;
        temp_y=n+1;
        temp_x=i+1;
        while(temp_x>=0 && temp_x<m && temp_y<m){
            no[temp_y++][temp_x++]-=1;
        }
        temp_y=n+1;
        temp_x=i-1;
        while(temp_x>=0 && temp_x<m && temp_y<m){
            no[temp_y++][temp_x--]-=1;
        }
        for(int j = n+1; j<m; j++){
            no[j][i]-=1;
        }
    }

}
int solution(int n) {
    int answer = 0;
    m=n;
    f(0);
    answer = ans;
    return answer;
}
int main(){
    solution(4);
    cout<<ans;
    return 0;
}