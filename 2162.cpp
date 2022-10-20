#define X first
#define Y second
#include <bits/stdc++.h>
using namespace std;
using pairs = pair<int,int>;
pair<pairs, pairs> line[3000];
int n;
int parent[3000];
int Rank[3000];
int union_size[3000];
int ccw(pairs a,pairs b,pairs c){
    int s = (a.first*b.second + b.first*c.second + c.first*a.second)
            - (a.second*b.first + b.second*c.first + c.second*a.first);
    if(s>0)return 1;
    else if(s<0) return -1;
    else return 0;
}
bool meet(pair<pairs, pairs> line1, pair<pairs,pairs>line2){
    pairs a = line1.first;
    pairs b = line1.second;
    pairs c = line2.first;
    pairs d = line2.second;
    int ab = ccw(a,b,c)*ccw(a,b,d);
    int cd = ccw(c,d,a)*ccw(c,d,b);
    if(ab == 0 && cd == 0){
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        return c<=b && a<=d ;
    }
    return ab<=0 && cd<=0 ;
}
int find(int x){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d;
    fill(Rank, Rank+3000, 1);
    fill(union_size, union_size+3000, 1);
    cin>>n;
    for(int i=0; i<n; i++){
        parent[i]=i;
        cin>>a>>b>>c>>d;
        line[i].first.X=a;
        line[i].first.Y=b;
        line[i].second.X=c;
        line[i].second.Y=d;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(meet(line[i], line[j])){
                int x = find(i);
                int y = find(j);
                if(x==y){
                    continue;
                }
                else{
                    if(Rank[x]<=Rank[y]){
                        parent[x]=y;
                        union_size[y]+=union_size[x];
                    }
                    else{
                        parent[y]=x;
                        union_size[x]+=union_size[y];
                    }
                }
            }
        }
    }    
    int ans=0;
    for(int i=0; i<n; i++){
        if(i==parent[i])ans+=1;
    }
    cout<<ans<<'\n';
    cout<<*max_element(union_size, union_size+n);
    return 0;
}