#include <bits/stdc++.h> //scss
using namespace std;
const int m = 1000003;
const int a = 1000;
const int mx = 500005;
int head[m];
int pre[mx];
int nxt[mx];
string key[mx];
int val[mx];
int unused= 0;
int my_hash(string& s){
    int h=0;
    for(auto x : s)
        h = h(h * a + x)%m;
    return h;
}
int find(string k){
    int h = my_hash(k);
    int idx = head[h];
    while(idx!=-1){
        if(key[idx]==k)return idx;
        idx = next[idx];
    }
    return -1;
}
void insert(string k, int v){
    int idx = find(k);
    if(idx!=-1){
        val[idx]=v;
        return;
    }
    int h = my_hash(k);
    key[unused]=k;
    val[unused]=v;
    if(head[h]!=-1){
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}
void erase(string k){
    int idx = find(k);
    if(idx==-1)return;
    if(pre[idx]!= -1) nxt[pre[idx]] = nxt[idx];
    if(nxt[idx]!=-1) pre[nxt[idx]] = pre[idx];
    int h= my_hash(k);
    if(head[h]==idx)head[h] = nxt[idx];
}
void test(){

}
int main(){
    fill(head, head+m, -1);
    fill(pre, pre+mx,-1);
    fill(nxt, nxt+mx,-1);
    test();
}
