#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct Event{
    bool isStart; 
    int time;
    int b;
    Event(bool s, int t, int b):isStart(s),time(t),b(b){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    cin>>n;
    vector<Event> events;
    for(int i = 0; i < n; i++){
        int start, end, b;
        cin>>start>>end>>b;
        events.push_back(Event(1,start,b));
        events.push_back(Event(0,end,b));
    }
    sort(events.begin(),events.end(),[](const Event &a, const Event &b){return a.time<b.time;});
    int free=0, buckets=0;
    for(int i = 0; i < events.size(); i++){
        if(events[i].isStart){
            if(events[i].b<=free){
                free-=events[i].b;
            }else{
                buckets+=(events[i].b-free);
                free=0;
            }
        }else{
            free+=events[i].b;
        }
    }
    cout<<buckets<<"\n";
}