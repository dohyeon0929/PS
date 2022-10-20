#include <bits/stdc++.h>
using namespace std;
void print(int num8, int num4, int num1){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,t;
    cin>>x>>t;
    if(x%8==0 && x/8 <= t){
        cout<<1<<'\n';
        cout<<t-x/8<<' '<<8;
        return 0;
    }
    else if(x%4==0 && x/4 <= t){
        cout<<1<<'\n';
        cout<<t-x/4<<' '<<4;
        return 0;
    }
    else if(x<=t){
        cout<<1<<'\n';
        cout<<t-x<<' '<<1;
        return 0;
    }
    
    else if(x/8 + (x%8) <=t){
        cout<<2<<'\n';
        cout<<t-x/8-x%8<<' '<<8<<'\n';
        cout<<t-x%8<<' '<<1<<'\n';
    }
    else if(x/4 + (x%4) <= t){
        cout<<2<<'\n';
        cout<<t-x/4-x%4<<' '<<4<<'\n';
        cout<<t-x%4<<' '<<1<<'\n';
    }
    else if(x/8 + ((x%8)/4) <= t && x%8%4==0){
        cout<<2<<'\n';
        cout<<t-x/8-((x%8)/4)<<' '<<8<<'\n';
        cout<<t-((x%8)/4)<<' '<<4<<'\n';
    }
    else{
        int count=0;
        int num = x;
        int num8 = num / 8;
        if(num8!=0)count++;
        num %= 8;
        int num4 = num / 4;
        if(num4!=0)count++;
        num %= 4;
        int num1 = num;
        if(num1!=0)count++;
        if(num8 + num4 + num1 > t){
            cout<<-1;
            return 0;
        }
        else{
            int now = t - (num8 + num4 + num1);
            cout<<count<<'\n';
            if(num8!=0){
                cout<<now<<' '<<8<<'\n';
                now += num8;
            }
            if(num4!=0){
                cout<<now<<' '<<4<<'\n';
                now+=num4;
            }
            if(num1!=0){
                cout<<now<<' '<<1;
            }
        }
    }
   return 0;
}