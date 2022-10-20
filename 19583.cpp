//7:6~
#include <bits/stdc++.h>
using namespace std;
map<string, bool> m;
int main(){
    int s,e,q;
    int a,b;
    scanf("%d:%d",&a,&b);
    s=a*100+b;
    scanf("%d:%d",&a,&b);
    e=a*100+b;
    scanf("%d:%d",&a,&b);
    q=a*100+b;
    int now;
    int ans=0;
    string name;
    while(scanf("%d:%d",&a,&b)!=EOF){
        // if(a==0&&b==0)break;
        cin>>name;
        now=a*100+b;
        if(now<=s){
            m[name]=1;
        }
        else if(e<=now&&now<=q){
            if(m[name]==1){
                m[name]=0;
                ans+=1;
            }
        }
	} while (getc(stdin) == ' ');
    cout<<ans;
    return 0;
}