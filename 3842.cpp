//입력 창에 N개의 주가 주어진다. 라는 말이 있으면 문제 푸는 입장에서 이해하기 쉬울 것 같음. 
//업무를 한 번도 안 받은 사람이 있을 수도 있지 않나...
#include <bits/stdc++.h>
using namespace std;
int work_time[] = {4,6,4,10};
vector<string> name;
map<string, int> m;
int Min = 123456789;
int Max = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<7; k++){
                cin>>s;
                if(s=="-"){
                    continue;
                }
                else{
                    if(m[s]==0)name.push_back(s);
                    m[s]+=work_time[j];

                }
            }
        }
    } 
    for(auto i : name){
        Max = max(Max, m[i]);
        Min = min(Min, m[i]);
    }
    if(Max - Min <= 12)cout<<"Yes";
    else cout<<"No";
    return 0;
}