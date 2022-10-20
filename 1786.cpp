#include <bits/stdc++.h>
using namespace std;
int k[1000001];
string subs[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t,p;
    getline(cin,t);
    t=" "+t;
    getline(cin,p);
    int basic_p_size = p.size();
    p=" "+p;
    // char final_token = p[p.size()-1];
    int now_ptr = 1;
    k[1]=0;
    cout<<k[1]<<' ';
    int final_k=0, final_cnt;
    for(int i=2; i<=p.size()-1; i++){
        if(p[i]==p[now_ptr] || i==p.size()-1){
            k[i]=now_ptr;
            now_ptr+=1;
        }
        else{
            if(p[i]==p[1]){
                k[i]=now_ptr=1;
                now_ptr=2;
            }
            else{
                k[i]=0;
                // if(i==p.size()-1){
                //     now_ptr = 
                // }
                now_ptr=1;
            }
        }
        // if(p[i]==final_token){
        //     final_k = max(final_k,k[i]);
        // }
        cout<<k[i]<<' ';
    }
    cout<<'\n';
    int ans=0;
    vector<int> ans_start;
    int start=1,cnt=1;
    int i=1;
    while(i<t.size()){
        cout<<"i : "<<i<<'\n';
        cout<<"start : "<<start<<'\n';
        cout<<"cnt : "<<cnt<<'\n';
        cout<<t[i]<<' '<<p[cnt]<<'\n'<<'\n';
        cout<<'\n';
        if(t[i]==p[cnt]){
            cnt++;
        }
        else{
            if(cnt!=1 ){
                start = i - k[cnt]+1;
                i--;
                cnt=k[cnt]+1;
                // start=start+cnt-1-k[cnt-1]+1;
                // i--;
            }
            else{
                start = i+1;
                cnt=1;
                // start=start+cnt-k[cnt-1];
                // cnt=k[cnt-1]+1;
            }
        }
        if(cnt>basic_p_size){ //원래 p보다 1 초과 
            ans+=1;
            ans_start.push_back(start);
            
            if(basic_p_size!=1){
                start = i - k[cnt-1]+1;
                cnt = k[cnt-1]+1;
                // start=start+cnt-1-k[cnt-1];
                // i--;
                // cnt=k[cnt-1];
            }
            else{
                start=i+1;
                cnt=1;
            }
            // else{
            //     start = 
            //     start=start+cnt-k[cnt]-1;
            //     cnt=k[cnt]+1;
            // }
            // cout<<"ans!!!!!!!!!!!!!!"<<'\n';
        }
        i++;
        // cout<<'\n';
    }
    cout<<ans<<'\n';
    for(auto iter : ans_start){
        cout<<iter<<' ';
    }
    return 0;
}