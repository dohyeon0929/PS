//1236
#define ll unsigned long long
#define Y first
#define X second
#include <bits/stdc++.h>
using namespace std;
ll n,r,c;
ll Count = 0;
vector<int> ans;
void f(pair<ll,ll>start, ll u);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>c;
    int u = 1<<(n-1);
    f(make_pair(0,0), u);
    return 0;
}
void f(pair<ll,ll>start, ll u){
    int dy[]={0,0,1,1};
    int dx[]={0,1,0,1};
    if(u==1){
        for(int i=0; i<4; i++){
            ll y = start.Y + dy[i];
            ll x = start.X + dx[i];
            if(y==r&&x==c){
                cout<<Count;
                return;
            }
            else Count++;
        }
        return;
    }
    f(make_pair(start.Y, start.X),u/2);
    f(make_pair(start.Y, start.X + u),u/2);
    f(make_pair(start.Y + u, start.X),u/2);
    f(make_pair(start.Y + u, start.X + u),u/2);
}
//영역 나누기로 알고리즘 변경하자. 이진수 이용해서
//가로 2^4 + 2^2+ 2^1, 세로 2^3+ ... 이런 식으로

