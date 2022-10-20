#define ll unsigned long long
#define MAX_NUM 0
#include <bits/stdc++.h>
using namespace std;
ll N[200003];
int Size=0;
void del();
void func(ll n);
void insert(ll temp);
void Swap(ll a,ll b);
void print();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n; 
    for(ll i=1; i<=n; i++){
        N[i] = MAX_NUM;
    }
    ll temp;
    for(ll i=0; i<n; i++){
        cin>>temp;
        if(temp==0){
            del();
        }
        else{
            insert(temp);     
        }
        // print();
    }
    return 0;
}
void del(){
    if(N[1]==MAX_NUM){
        cout<<0<<'\n';
        return;
    }
    cout<<N[1]<<'\n';
    N[1]=N[Size];
    N[Size--]=MAX_NUM;
    func(1);
}
void insert(ll temp){
    N[++Size]=temp;
    int now = Size;
    while((N[now/2]<N[now])&&now!=1){
        Swap(now/2, now);
        now/=2;
    }
}
void func(ll n){ // 위에서 아래로 정렬 
    if((N[n]>N[n*2]&&N[n]>N[n*2+1])||n*2>Size) return;
    ll o = n*2;
    if(N[o]<N[o+1]) o++;
    Swap(n,o);
    func(o);
    return;
}
void Swap(ll a, ll b){
    ll temp = N[a];
    N[a]=N[b];
    N[b]=temp;
    return;
}
void print(){

    cout<<"now heap : ";
    for(int i=1; i<Size; i++){
        cout<<N[i]<<' ';
    }
    cout<<'\n';
}