#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<ll> costs(n);
    for(int i = 0; i < n; i++)
        cin>>costs[i];
    sort(costs.begin(),costs.end());
    int p=1; 
    ll cost=costs[n-1];
    ll profit=cost; 
    ll optCost=cost; 
    for(int i = n-2; i>=0; i--){
        if(costs[i]!=cost){
            if(cost*p >= profit){
                profit=cost*p;
                optCost=cost; 
            }
            cost=costs[i]; 
        }
        p++;
    }
    cout<<profit<<" "<<optCost<<"\n";
    return 0;
}