#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, n, x, y, ans;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        bool flag=false;
        cin>>m>>n>>x>>y;
        int lcm = m/__gcd(m,n)*n;
        for (int i = x; i <= lcm; i += m)
        {
            if (i % n == y ||(n==y && i%n==0))
            {
                flag=true;
                ans = i;
                break;
            }
        }
        
        if(flag) cout<<ans<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}