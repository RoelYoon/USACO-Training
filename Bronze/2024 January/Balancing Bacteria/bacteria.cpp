#include <iostream>
#define ll long long
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll patches[200005];
    for(int i = 1; i <= n; i++){
        cin>>patches[i];
    }
    ll callTimes = 0;
    ll update[200005]{};
    for(int i = 1; i <= n; i++){
        patches[i]+=update[i];
        bool add = patches[i]<0;
        callTimes += (abs(patches[i]));
        for(int j = n; j>=i; j--){
            update[j]+=((j)*(add?1:-1));
        }
    }
    cout<<callTimes<<"\n";
}