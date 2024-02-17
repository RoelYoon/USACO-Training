#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int ID = 0;
struct Plant{
    ll h;
    ll a;
    int id; 
    Plant(){
        cin>>h;
        id = ID++;
    }
};
bool pass(vector<Plant> &plants, vector<ll> &t){
    for(int i = 0; i < plants.size(); i++){
        if(i != t[plants[i].id]-(i==0?0:(plants[i-1].h==plants[i].h?1:0))){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll minDays = 0;
        vector<Plant> plants(n);
        for(int i = 0; i < n; i++){
            cin>>plants[i].a;
        }
        vector<ll> t(n);
        for(int i = 0; i < n; i++){
            cin>>t[i];
        }
        sort(plants.begin(),plants.end(),[](Plant &a, Plant &b){return a.h>b.h;});
        bool impossible=false;
        while(!pass(plants,t)&&minDays<100000){
            for(int i = 0; i < n; i++){
                plants[i].h+=plants[i].a;
            }
            sort(plants.begin(),plants.end(),[](Plant &a, Plant &b){return a.h>b.h;});
            minDays++;
        }
        if(minDays>=100000){
            impossible=1;
        }
        cout<<(impossible?-1:minDays)<<"\n";
        ID=0;
    }
}
