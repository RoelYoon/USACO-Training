#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int ID = 0;
struct Plant{
    ll a;
    ll b;
    int id; 
    Plant(){
        cin>>a;
        id = ID++;
    }
};
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
        bool impossible = false;
        ll lowerBound = 0;
        ll upperBound = 1000000000;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j){continue;}
                int a = plants[i].a;
                int b = plants[i].b;
                int c = plants[j].a;
                int d = plants[j].b;
                if(b==d){
                    impossible=1;
                    break;
                }else if(b > d){
                    upperBound = (c-a)/(b-d) - 1; 
                }else if(b<d){
                    lowerBound = (c-a)/(b-d) + 1;
                }
            }
            if(upperBound<lowerBound){
                impossible=1;
            }else if(upperBound==lowerBound){
                minDays=lowerBound;
                break;
            }
            if(impossible){
                break;
            }
        }
        cout<<(impossible?-1:minDays)<<"\n";
        ID=0;
    }
}
