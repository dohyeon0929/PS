#include <bits/stdc++.h>
using namespace std;
long double ans;
long long n,l,w,h;
void f(long double Start, long double End){
    if(abs(Start-End)<pow(10,-10)){
        ans=End;
        return;
    }
    long double mid = (Start+End)/2;
    long long now_l = floor(l/mid);
    long long now_w = floor(w/mid);
    long long now_h = floor(h/mid);
    long long now = now_l*now_w*now_h;
    if(now>=n)f(mid,End);
    else f(Start,mid);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>w>>h;
    long double End = (l<w ?l:w );
    End = (End<h ? End:h);
    f(0,End);
    printf("%.10Lf",ans);
    // cout<<ans;
    return 0;
}