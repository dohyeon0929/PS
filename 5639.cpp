#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
    
        Node(){
            val = 0;
            left=NULL;
            right=NULL;
        }
        Node(int v){
            val = v;
            left = NULL;
            right = NULL;
        }
};
int n;
void Insert(Node* temp, int temp_val);
void Find(Node* temp);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool flag=true;
    Node* root;
    int a;
    while(cin>>a){
        if(flag){
            flag=false;
            root = new Node(a);
            continue;
        }
        Insert(root, a);
    } 
    Find(root);
    return 0;
}
void Find(Node* temp){
    if(temp==NULL)return;
    Find(temp->left);
    Find(temp->right);
    cout<<temp->val<<'\n';
}
void Insert(Node* temp, int temp_val){
    Node* parent;
    if(temp_val<temp->val){
        if(temp->left==NULL){
            temp->left = new Node(temp_val);
        }
        else{
            Insert(temp->left, temp_val);
        }
    }
    else{
        if(temp->right==NULL){
            temp->right = new Node(temp_val);
        }
        else{
            Insert(temp->right, temp_val);
        }
    }
}