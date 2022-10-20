#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> s_num;
    vector<char> s_buho;
    ll n;
    int end_num=1,end_buho=0;
    string sik;
    cin>>n;
    cin>>sik;
    int timer=n+1;
    bool closed=false;
    s_num.push_back(sik[0]-'0');
    for(int i=1; i<n; i++){
        if(i==timer){
            closed=false;
        }
        if(i%2==0){
            s_num.push_back(sik[i]-'0');
            end_num++;
            if(end_buho>=2){
                if(s_buho[end_buho-1]=='+'){
                    if(s_buho[end_buho-2]=='*'){
                        if(!closed){
                            s_num.pop_back();
                            s_buho.pop_back();
                            end_buho--;
                            end_num--;
                            s_num[end_num-1]+=sik[i]-'0';
                            closed=true;
                            timer = i+3;
                        }
                    }
                }
                else if(s_buho[end_buho-1]=='-'){
                    if(s_buho[end_buho-2]=='-'){
                        if(!closed){
                            if(s_num[end_num-2]-s_num[end_num-1]<0){
                                s_num.pop_back();
                                s_buho.pop_back();
                                end_buho--;
                                end_num--;
                                s_num[end_num-1]-=sik[i]-'0';
                                // cout<<s_num[end_num-1]<<'\n';
                                closed=true;
                                timer = i+3;
                            }
                        }
                    }
                }
            }
        }
        else{
            s_buho.push_back(sik[i]);
            end_buho++;
        }
    }
    ll ans = sik[0]-'0';
    for(int i=1, j=0; i<=end_buho; i++, j++){
        if(s_buho[j]=='+'){
            ans+=s_num[i];
        }
        else if(s_buho[j]=='-'){
            ans-=s_num[i];
        }
        else if(s_buho[j]=='*'){
            ans*=s_num[i];
        }
    }
    cout<<ans;
    return 0;
}