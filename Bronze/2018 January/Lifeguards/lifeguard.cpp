#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct Time{
    int time;
    int lifeguard;
    Time(int lifeguard):lifeguard(lifeguard){
        cin>>time;
    }
};
int maxCoverTime(vector<Time> &times, int firedLifeguard){
    bool shift[105]{};
    int coveredTime = 0;
    int onDuty=0;
    for(int i = 0; i < times.size(); i++){
        shift[times[i].lifeguard]=times[i].lifeguard!=firedLifeguard?!shift[times[i].lifeguard]:0;
        if(onDuty>0){
            coveredTime+=times[i].time-times[i-1].time;
        }
        if(shift[times[i].lifeguard]){
            //added to shift
            onDuty++;
        }else if(times[i].lifeguard!=firedLifeguard){
            //removed from shift
            onDuty--;
        }
    }
    if(onDuty>0){
        coveredTime+=times[n-1].time-times[n-2].time;
    }
    return coveredTime;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    cin>>n;
    vector<Time> times;
    for(int i = 0; i < n; i++){
        times.push_back(Time(i));
        times.push_back(Time(i));
    }
    sort(times.begin(),times.end(),[](const Time&a, const Time &b){return a.time<b.time;});
    int maxCover = 0;
    for(int i = 0; i < n; i++){
        maxCover = max(maxCover,maxCoverTime(times,i));
    }
    cout<<maxCover<<"\n";
}