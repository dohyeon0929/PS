//6:00~7:11...ㅎ
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
    ios::sync_with_stdio(0);
    cin.tie(0);
    string query;
    string arr;
    string temp2;
    int t,num,temp,z,start,end;
    bool errorFlag, reverse;

    cin>>t;
    for(int i=0; i<t; i++){
        vector<int> v;
        cin>>query;
        cin>>num;
        cin>>arr;
        for(int j=1; j<arr.size(); j++){
            if(arr[j]!=']'&&arr[j]!=','){
                temp2+=arr[j];
            }
            else{
                stringstream ss(temp2);
                ss>>z;
                v.push_back(z);
                temp2="";
            }
        }
        start=0; end=num-1; reverse=false; errorFlag=false;
        for(int j=0; j<query.length(); j++){
            char now = query[j];
            if(now=='R'){
                reverse=!reverse;
            }
            else if(now=='D'){
                if(start>end){
                    end=start-1;
                    cout<<"error"<<'\n';
                    errorFlag=true;
                    break;
                }
                if(reverse==true)
                    end--;
                else
                    start++;
            }
        }
        if(errorFlag)continue;
        if(start>end){
            cout<<"[]\n";
            continue;
        }
        cout<<'[';
        if(reverse){
            for(int j=end; j>start; j--){
                cout<<v[j]<<',';
            }
            cout<<v[start]<<"]\n";
        }
        else{
            for(int j=start; j<end; j++){
                cout<<v[j]<<',';
            }
            cout<<v[end]<<"]\n";
        }
    }
    return 0;
}