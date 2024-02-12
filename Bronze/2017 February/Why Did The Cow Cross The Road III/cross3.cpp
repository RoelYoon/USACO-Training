#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct Cow{
    int arriveTime;
    int questionTime;
    Cow(){cin>>arriveTime>>questionTime;}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    cin>>n;
    vector<Cow> cows(n);
    sort(cows.begin(),cows.end(),[](const Cow& a, const Cow &b){return a.arriveTime<b.arriveTime;});
    int time = 0;
    for(int i = 0; i < n; i++){
        time=max(time,cows[i].arriveTime);
        time+=cows[i].questionTime;
    }
    cout<<time<<"\n";
}
