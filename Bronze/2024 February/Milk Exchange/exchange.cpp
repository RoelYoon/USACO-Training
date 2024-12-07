#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define nx(p) ((p+1)%n)
#define pv(p) ((p-1+n)%n)
using namespace std;
struct Event{
    ll time;
    int node;
    Event(){}
    Event(ll t, int n):time(t),node(n){}
    bool operator<(const Event &k) const {
        return time>k.time;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; ll m; cin>>n>>m;
    string s; cin>>s;
    vector<int> graph(n);
    vector<ll> milk(n);
    vector<ll> dm(n,-1);
    ll totalMilk = 0;
    for(int i = 0; i < n; ++i){
        cin>>milk[i];
        totalMilk+=milk[i];
        graph[i]=s[i]=='L'?pv(i):nx(i);
        ++dm[graph[i]];
    }
    priority_queue<Event> pq;
    ll excessMilk = 0; // excess milk produced per unit time
    for(int i = 0; i < n; ++i){
        if(dm[i]<0)
            pq.push({milk[i],i});
        else
            excessMilk+=dm[i];
    }
    ll totalExcessMilk = 0; // total excess milk produced
    ll time = 0;
    while(!pq.empty() && time<m){
        Event event = pq.top();
        event.time=min(event.time,m);
        ll dt = event.time-time;
        totalExcessMilk+=dt*excessMilk;
        // deactivation
        time=event.time;
        while(!pq.empty() && pq.top().time==time){
            int reducedNode = graph[pq.top().node]; pq.pop();
            --dm[reducedNode];
            if(dm[reducedNode]<0)
                pq.push({time+milk[reducedNode],reducedNode});
            else
                --excessMilk;
        }
    }
    if(time<m){
        ll dt = m-time;
        totalExcessMilk+=dt*excessMilk;
    }
    cout<<totalMilk-totalExcessMilk<<"\n";
}