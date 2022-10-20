#define X first
#define Y second
#define ld long double
#include <bits/stdc++.h>
using namespace std;
using pairs= pair<ld, ld>;
vector<pairs> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ld a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    ld ans=0.0L;
    ld temp;
    for(int i=1; i<=n-2; i++){
        pairs a0 = v[0];
        pairs a1 = v[i];
        pairs a2 = v[i+1];
        temp = ((a0.X*a1.Y+a1.X*a2.Y+a2.X*a0.Y)-(a1.X*a0.Y+a2.X*a1.Y+a0.X*a2.Y))/2;
        cout<<"\ntemp : "<<temp<<'\n';
        printf("%lf\n",temp);
        ans+=temp;
        // cout<<ans<<'\n';
    }
    if(ans<0)ans*=-1;
    printf("%.1Lf",ans);
    // cout<<(ld)(ans);
    // printf("%.1Lf",ans);
    return 0;
}
