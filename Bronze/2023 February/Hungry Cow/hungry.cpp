/*
ID: roelyoon
TASK: name
LANG: C++                 
*/
#include <vector>
#include <utility>
#include <stdio.h>
using namespace std;
typedef long long ll; 
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,t, numOfHay=0; 
    scanf("%lld%lld",&n,&t);
    t++;
    vector<pair<ll,int> > days;
    for(int i = 0; i < n; i++){
        ll d,b;
        scanf("%lld%lld",&d,&b);
        days.push_back(make_pair(d,b));
    }
    ll day = days[0].first; 
    ll count = 0;
    pair<ll,int> nextDay;
    for(int i = 0; i < days.size(); i++){
        if(i<n-1){nextDay.first=days[i+1].first;}
        else{nextDay.first=t;}
        numOfHay+=days[i].second;
        ll dif = nextDay.first-day;
        if(dif>=numOfHay){
            count+=numOfHay;
            numOfHay=0;
        }else{
            count+=dif;
            numOfHay-=dif;
        }
        day=nextDay.first;
    }
    printf("%lld",count);
}