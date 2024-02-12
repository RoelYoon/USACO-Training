#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crossroad.in","r",stdin);
    freopen("crossroad.out","w",stdout);
    cin>>n;
    int roads[11]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int count = 0;
    for(int i = 0; i < n; i++){
        int cow, road;
        cin>>cow>>road;
        count+=roads[cow]!=-1? roads[cow]!=road ? 1 : 0 : 0;
        roads[cow]=road;
    }
    cout<<count<<"\n";
}
