#include <bits/stdc++.h>
using namespace std;
int inorder[100002];
int postorder[100002];
int position[100002][2];
bool checked[100002];
int parent[100002];
int child[100002][2];
int n;
void f(int root){//100
    bool flag=0;
    checked[root]=1;
    if(position[root][0]+1<=n){
        int child1_1 = inorder[position[root][0]+1];
        if(!checked[child1_1]){
            int child1 = postorder[position[child1_1][1]-1];
            if(position[child1][0]<position[root][0])flag=1;
            else flag=0;
        }
    }
    if(flag==1){
        if(position[root][0]+1<=n){
            int child1_1 = inorder[position[root][0]+1];
            if(!checked[child1_1]){
                int child1 = postorder[position[child1_1][1]-1];
                if(!checked[child1]){
                    child[root][0]=child1;
                    cout<<"child["<<root<<"]["<<0<<"] = "<<child[root][0]<<'\n';
                    f(child1);//0
                }
            }
        }
        if(position[root][1]-1>=1){
            int child2 = postorder[position[root][1]-1];
            if(!checked[child2]){
                child[root][1]=child2;
                cout<<"child["<<root<<"]["<<1<<"] = "<<child[root][1]<<'\n';
                f(child2);//50
            }
        }
    }
    else{
        if(position[root][0]-1>=1){
            int child1 = inorder[position[root][0]-1];
            if(!checked[child1]){
                child[root][0]=child1;
                cout<<"child["<<root<<"]["<<1<<"] = "<<child[root][1]<<'\n';
                f(child1);//0
            }
        }
        if(position[root][1]-1>=1){
            int child2 = postorder[position[root][1]-1];
            if(!checked[child2]){
                child[root][1]=child2;
                cout<<"child["<<root<<"]["<<1<<"] = "<<child[root][1]<<'\n';
                f(child2);//50
            }
        }
    }
    
    
}
void treeSearch(int root){
    if(root==0)return;
    cout<<root<<' ';
    treeSearch(child[root][0]);
    treeSearch(child[root][1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a;
    for(int j=1; j<=n; j++){
        cin>>a;
        inorder[j]=a;
        position[a][0]=j;
    }
    for(int j=1; j<=n; j++){
        cin>>a;
        postorder[j]=a;
        position[a][1]=j;
    }
    f(postorder[n]);
    treeSearch(postorder[n]);
    return 0;
}