#define MAX_SIZE 1000001
#include <bits/stdc++.h>
using namespace std;
// set<int> parent[1000001];
// int parent[1000001];
int arr[1000001];
int parent[MAX_SIZE];
int Rank[MAX_SIZE];
bool flag;

int Find(int x){
    if (x==parent[x]){
        return x;
    }
    else{
        int y = Find(parent[x]);
        parent[x] = y;
        return y;
    }
}
void Union(int x, int y, int i){
    x = Find(x);
    y = Find(y);

    if (x == y){
        cout<<i;
        flag=true;
        return;
    }

    if (Rank[x] > Rank[y]){
        parent[y] = x;
        Rank[x] += Rank[y];
    }
    else {
        parent[x] = y;
        Rank[y] += Rank[x];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    flag = false;
    cin>>n>>m;
    int a,b;
    for (int i=1; i<MAX_SIZE; i++)
        parent[i] = i;
    for (int i=1; i<MAX_SIZE; i++)
	    Rank[i] = 1;
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        Union(a,b,i);
        if(flag)return 0;
    } 

    cout<<0;
    return 0;
}