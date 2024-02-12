#include <iostream>
#include <algorithm> 
using namespace std;
typedef long long ll; 
int main(){
    int n,k; cin>>n>>k;
    ll days[100005];
    for(int i = 0; i < n; i++)
        cin>>days[i];
    ll minCost=k+1;
    for(int i = 1; i < n; i++)
        minCost+=min(days[i]-days[i-1],(ll)k+1); 
    cout<<minCost<<"\n";
    return 0;
}