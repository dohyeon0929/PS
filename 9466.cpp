#include <bits/stdc++.h>
using namespace std;
int state[100011];
int arr[100011];
int t,n,a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        fill(arr,arr+n+1,0);
        for(int j=1; j<=n; j++){
            cin>>arr[j]; 
        }
        fill(state,state+n+1,0);
        stack<int> s;
        while(!s.empty())s.pop();
        for(int j=1; j<=n; j++){
            if(state[j]!=0)continue;
            if(j==arr[j]){
                state[j]=2;
                continue;
            }
            s.push(j);
            while(state[arr[s.top()]]==0){
                state[s.top()]=1;
                s.push(arr[s.top()]);
            }
            if(state[arr[s.top()]]!=1){
                if(state[j]==2&&state[s.top()]==2)continue;
                else{
                    while(!s.empty()){
                        state[s.top()]=-1;
                        s.pop();
                    }
                }
            }
            else{
                int temp = arr[s.top()];
                while(!s.empty()){
                    state[s.top()]=2;
                    s.pop();
                    if(s.top()==temp) {
                        state[s.top()]=2;
                        s.pop();
                        break;
                    }
                }
                while(!s.empty()){
                    if(state[s.top()]!=2)
                        state[s.top()]=-1;
                    s.pop();
                }
            }
            // for(int i=1; i<=n; i++){
            //     cout<<state[i]<<' ';
            // }
            // cout<<'\n';
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(i!=arr[i]&&state[i]==-1)ans+=1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}