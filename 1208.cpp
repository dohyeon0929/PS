#define ll long long
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<ll> ans_v;
int ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        // cout<<"i : "<<i<<'\n';
        ll ans_pointer=0;        
        int temp = v[i];
        ans_pointer = ans_pointer | (1<<i);
        int aaa,bbb;
        ll pointer; 
        vector<bool> checked(1000001);
        checked[i]=1;
        int num_check=1;
        // cout<<"?\n";
        aaa = m - temp;
        auto bb=lower_bound(v.begin(), v.end(), aaa);
        bbb=bb - v.begin();
        while(temp!=m && num_check!=n){
            // cout<<"temp : "<<temp<<"  aaa : "<<aaa<<'\n';
            // cout<<"bbb : "<<bbb<<"   v[bbb] : "<<v[bbb]<<'\n';
            if(checked[bbb]){
                // cout<<"no bbb : "<<bbb<<", no v[bbb] : "<<v[bbb]<<'\n';
                auto temptemp = next(bb);
                bb=temptemp;
                bbb=bb-v.begin();

                // num_check++;
                continue;
            }
            else{
                ans_pointer = ans_pointer | (1<<bbb);
                temp+=v[bbb];
                checked[bbb]=1;
                num_check++;

                aaa = m - temp;
                bb=lower_bound(v.begin(), v.end(), aaa);
                bbb = bb - v.begin();
            }
        }
        bool flag=true;
        if(temp==m){
            for(int j=0; j<ans_v.size(); j++){
                if(ans_pointer == ans_v[j])flag = false;
            }
            if(flag){
                // cout<<"\n!!! ans +1\n";
                ans+=1;
                ans_v.push_back(ans_pointer);
            }
        }
    }
    cout<<ans;
    return 0;
}