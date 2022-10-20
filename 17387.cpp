#define ll long long
#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double X1, Y1, X2, Y2, X3, Y3, X4, Y4;
double f1(ll x){
    return a*x+b;
}
double f2(ll x){
    return c*x+d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int super_token1=0;
    int super_token2=0;
    ll aa,bb,cc,dd;

    cin>>aa>>bb>>cc>>dd;
    if(aa<cc){
        X1=aa; Y1=bb; X2=cc; Y2=dd;
    }
    else{
        X2=aa; Y2 =bb; X1=cc; Y1=dd;
    }
    if(X2==X1){
        super_token1 =1;
    }

    cin>>aa>>bb>>cc>>dd;
    if(aa<cc){
        X3=aa; Y3=bb; X4=cc; Y4=dd;
    }
    else{
        X4=aa; Y4 =bb; X3=cc; Y3=dd;
    }
    if(X3==X4){
        super_token2 =1;
    }

    if(!super_token1){
        a=(Y2-Y1)/(X2-X1);
        b=Y1 - a*X1;
    }
    if(!super_token2){
        c=(Y4-Y3)/(X4-X3);
        d=Y3 - c*X3;
    }
    
    int token;
    int temp;
    if(!super_token1&&super_token2){ //2이 비정상 
        if(X1<=X3&&X3<=X2){
            if((Y3<=f1(X3)&&f1(X3)<=Y4)||(Y3>=f1(X3)&&f1(X3)>=Y4)){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    else if(!super_token2&&super_token1){//1이 비정상 
        if(X3<=X1&&X1<=X4){
            if((Y1<=f2(X1)&&f2(X1)<=Y2)||(Y1>=f2(X1)&&f2(X1)>=Y2)){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    else if(super_token1&&super_token2){
        if(X1==X3){
            if(((Y3<=Y1&&Y1<=Y4)||(Y4<=Y1&&Y1<=Y3))||((Y3<=Y2&&Y2<=Y4)||(Y4<=Y2&&Y2<=Y3))){
                cout<<1;
                return 0;
            }
            else{
                cout<<0; 
                return 0;
            }
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(!super_token1&&!super_token2){
        for(ll i=-1000000; i<=1000000; i++){
            if(abs(f1(i )-f2(i ))<0.00000001){
                temp=0;
            }
            else if(f1(i)>f2(i)){
                temp = 1;
            }
            else if(f1(i)<f2(i)){
                temp=-1;
            }

            if(i==-1000000){
                if(temp==0){
                    if(X1<=i&&i<=X2&&X3<=i&&i<=X4){
                        cout<<1;
                        return 0;
                    }
                }
            }
            else{
                if(temp!=token){
                    if(X1<=i&&i<=X2&&X3<=i&&i<=X4){
                        cout<<1;
                        return 0;
                    }
                }
                else{
                    if(X1<=i&&i<=X2&&X3<=i&&i<=X4){
                        if(temp==0){
                            cout<<1;
                            return 0;
                        }
                    }
                }
            }
            token = temp;
        }
    }
    cout<<0;
    return 0;
}