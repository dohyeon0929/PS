#define INF 123456789
#include <bits/stdc++.h>
using namespace std;
int arr[17][17];
int Cost[16][1<<16];
int final_bit;
int n;
int dfs(int node, int bit){ //가장 마지막으로 간 점 node, 현재 상황 bit
    if(bit == final_bit){ //다 돌았을 때 
        if(arr[node][0]==0)return INF; //마지막에 길이 없으면 INF
        else return arr[node][0]; //길 있으면 마지막 노드 -> 첫 노드 거리 반환 
    }
    if(Cost[node][bit]!=-1)return Cost[node][bit]; //!!! 이미 계산 했던 거면 또 계산하는 거 막기 (dp의 성격)
    Cost[node][bit]=INF; //min을 계속 할 거라서 초기값을 INF로 설정 
    for(int i=0; i<n; i++){ //바로 다거에 갈 지점들 
        if(arr[node][i]==0)continue; //가는 길 없으면 스킵
        if((bit & (1<<i))==(1<<i))continue; //갔던 데 또 가는 거 막기

        Cost[node][bit]=min(Cost[node][bit], arr[node][i]+dfs(i, bit|(1<<i)));
        //node ~ 끝까지 dfs한 결과를 Cost[node][bit]에 저장 
    }
    return Cost[node][bit]; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    final_bit = (1<<n)-1;
    // cout<<final_bit<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    memset(Cost,-1,sizeof(Cost));
    cout<<dfs(0,1);
    return 0;
}