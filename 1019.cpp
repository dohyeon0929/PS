#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll ans[10];
ll ten[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n; 
    for(int i=1; i<10; i++){
        ten[i] = pow(10,i-1)*i + ten[i-1]; // 100(tem[2]) 이면 20개씩 
    }    
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int now = s.size()-1;
    while(now>=0){ //10
        int token = s[now]-'0';
        // if(now==s.size()-1) i=1;
        //24일 때 20 21 22 23 24 의 2를 더하기만 하면 됨 
        if(now>=0){
            for(int i=0; i<=token; i++){
                for(int j=0; j<10; j++){
                    ans[j]+=ten[now];
                }
                if(now==s.size()-1){
                    if(i>1) ans[i-1]+=pow(10,now);
                }
                else{
                    if(i!=token) ans[i]+=pow(10,now);
                }
                // if(now==s.size()-1 && i==0)ans[0]-=pow(10,now);
            }
            if(now>0){
                string news = s.substr(0,now);
                reverse(news.begin(), news.end());
                // cout<<news<<'\n';
                ll aaa= stoll(news);
                ans[token]+=aaa+1;
            }
       }
        // else{
        //     for(int i=1; i<=token; i++) ans[i]+=1; 
        // }
       now--;
    }
    for(int i=0; i<10; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}