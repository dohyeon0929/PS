#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> primes;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            primes.push_back(i);
            n/=i;
        }
    }
    if(n!=1){
        primes.push_back(n);
    }
    int size = primes.size();
    for(int i=0;i<size;i++){
        cout<<primes[i]<<'\n';
    }
    return 0;
}