#define ll long long
#include <bits/stdc++.h>
using namespace std;
vector<bool> check(1000010);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll Min,Max;
    cin>>Min>>Max;
    for(ll i=2; i*i<=Max; i++){
        ll tmp = Min/(i*i);
        if(Min%(i*i))tmp++; //나머지가 있다 = tmp에 다시 i*i를 곱했을 때 Min보다 작다 
        while(tmp*i*i<=Max){
            check[tmp*i*i-Min]=1;
            tmp++;
        }
    }
    ll cnt=0;
    for(int i=0; i<=Max-Min; i++){
        if(!check[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}