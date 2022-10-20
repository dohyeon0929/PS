#include <bits/stdc++.h>
using namespace std;
int arr[100001][2];
int position[100001][2];
int parent[100001];
int realchecked[100001];
vector<int> child[100001];
int n;
void f(int start, int start1, int root){
    if(start1>root)return;
    int i=position[arr[root][1]][0]-start+start1;
    if(i-1>=start1&&realchecked[arr[i-1][1]]==0){
        child[arr[root][1]].push_back(arr[i-1][1]);
        realchecked[arr[i-1][1]]=1;
        f(start, start1, i-1);
    }
    else child[arr[root][1]].push_back(0);

    if(start1>root-1||realchecked[arr[root-1][1]]==1) child[arr[root][1]].push_back(0);
    else{
        child[arr[root][1]].push_back(arr[root-1][1]);
        realchecked[arr[root-1][1]]=1;
        f(position[arr[root][1]][0]+1, i, root-1);
    }
}
void treeSearch(int root){
    if(root<=0)return;
    cout<<root<<' ';
    treeSearch(child[root][0]);
    treeSearch(child[root][1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin>>arr[j][i];
            position[arr[j][i]][i]=j;
        }
    }
    f(0, 0, n-1);
    treeSearch(arr[n-1][1]);
    return 0;
}