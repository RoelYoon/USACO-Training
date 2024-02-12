#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,m; cin>>n>>m;
    vector<int> haybales(n); 
    for(int i = 0; i < n; i++)
        cin>>haybales[i];
    sort(haybales.begin(),haybales.end());
    for(int i = 0; i < m; i++){
        int a,b,count=0;
        cin>>a>>b;
        int lowBound = lower_bound(haybales.begin(),haybales.end(),a) - haybales.begin();
        int upBound = upper_bound(haybales.begin(),haybales.end(),b) - haybales.begin();
        if(lowBound != -1 && upBound != -1){count=upBound-lowBound;}
        cout<<count<<"\n";
    }
}