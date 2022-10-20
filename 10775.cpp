#define MAX 100001
#include <bits/stdc++.h>
using namespace std;
int arr[MAX];
int parent[MAX];
int Rank[MAX];
int group[MAX];
int next_num[MAX];
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
void Union(int a, int b){ // O (log N)
    int x = Find(a);
    int y = Find(b);
    if(x==y)return ;
    else{
        if(Rank[x]<Rank[y]){
            parent[x]=y;
        }
        else if(Rank[x]>Rank[y]){
            parent[y]=x;
        }
        else{
            parent[y]=x;
            Rank[y]++;
        }
        next_num[y] = next_num[x];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    fill(Rank, Rank+n+1, 1);
    for(int i=1; i<=n; i++){
        parent[i]=i;
        next_num[i] = i;
    }
    int ans=0;

    for(int j=0; j<m; j++){ //10^5
        int i = arr[j];
        
        if(next_num[i]==i){
            ans+=1;
            next_num[i]=i-1;
            if(i!=1){
                if(next_num[i-1]!=i-1){
                    Union(i-1, i);
                }
            }
            if(i!=n){
                if(next_num[i+1]!=i+1){
                    Union(i, i+1);
                }
            }
        }
        else{
            int used = next_num[Find(i)];
            if(used==0){
                cout<<ans;
                return 0;
            }
            else{
                ans+=1;
                next_num[used]=used-1;
                if(used!=1){
                    if(next_num[used-1]!=used-1){
                        Union(used-1, used);
                    }
                }
                if(used!=n){
                    if(next_num[used+1]!=used+1){
                        Union(used, used+1);
                    }
                }
            }
        }
   }
    if(ans>=n)cout<<n;
    else cout<<ans;
    return 0;
}