#include <iostream>
#include <vector>
#define MAX 1000005
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n>>q;
    vector<int> a(n);
    int v[MAX]{},pv[MAX]{};
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    for(int i = 0; i < n; ++i){
        int t; cin>>t;
        a[i]-=t;
    }
    for(int i = 0; i < n; ++i)
        if(a[i]>=0)
            ++v[a[i]];
    pv[0]=v[0];
    for(int i = 1; i < 1000005; ++i)
        pv[i]=pv[i-1]+v[i];
    for(int i = 0; i < q; ++i){
        int vs,s; cin>>vs>>s;
        cout<<(pv[MAX-1]-pv[s]>=vs?"YES\n":"NO\n");
    }
}