#define ll long long
#define MAX 10001
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
int v,e;
vector<bool> checked(MAX);
set<tuple<int,int,int>> s;
int uni[MAX];
int Rank[MAX];
int Find(int a){
    if(a==uni[a])return a;
    return Find(uni[a]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    if(Rank[a]<Rank[b]){
        uni[a]=b;
    }
    else if(Rank[a]>Rank[b]){
        uni[b]=a;
    }
    else{
        uni[a]=b;
        Rank[b]++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v,e;
    cin>>v>>e;
    int a,b,c;
    for(int i=0; i<=v; i++){
        uni[i]=i;
    }
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        s.insert({c,a,b});
    }
    ll ans=0;
    while(!s.empty()){
        tuple<int,int,int> temp = *(s.begin());
        if(checked[get<1>(temp)]&&checked[get<2>(temp)]){
            if(Find(get<1>(temp))==Find(get<2>(temp))){
                s.erase(s.begin());
                continue;
            }
        }
        checked[get<1>(temp)]=checked[get<2>(temp)]=1;
        Union(get<1>(temp), get<2>(temp));
        ans+=(get<0>(temp));
        s.erase(s.begin());
    }
    cout<<ans;
    return 0;
}