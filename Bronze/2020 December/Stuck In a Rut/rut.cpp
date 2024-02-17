#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
struct Cow{
    bool dir; //1 - north 0- east
    ll x;
    ll y;
    int id;
    Cow(){}
    Cow(ll x,ll y,bool dir):x(x),y(y),dir(dir){
        static int ID = 0;
        id=ID++;
    }
};
int n;
vector<Cow> cows;
unordered_map<ll,Cow> xMap;
unordered_map<ll,Cow> yMap;
vector<ll> northX;
vector<ll> eastY;
vector<ll> maxD;
vector<bool> found;
void findMax(int i){
    if(found[i]){return;}
    found[i]=true;
    Cow &c = cows[i];
    if(cows[i].dir){
        //north
        for(int j = 0; j < eastY.size(); j++){
            ll t1 = eastY[j]-c.y;
            if(t1>0){
                Cow c2 = yMap[eastY[j]];
                ll t2 = c.x - c2.x;
                if(t2 > 0){
                    if(t2<t1){
                        findMax(c2.id);
                        if(maxD[c2.id]==-1 || maxD[c2.id]>=t2){
                            maxD[i]=t1;
                            break;
                        }
                    }
                }
            }
        }
    }else{
        //east
        for(int j = 0; j < northX.size(); j++){
            ll t1 = northX[j]-c.x;
            if(t1>0){
                Cow c2 = xMap[northX[j]];
                ll t2 = c.y - c2.y;
                if(t2 > 0){
                    if(t2<t1){
                        findMax(c2.id);
                        if(maxD[c2.id]==-1 || maxD[c2.id]>=t2){
                            maxD[i]=t1;
                            break;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        char c;
        ll x,y;
        cin>>c>>x>>y;
        cows.push_back(Cow(x,y,c=='N'));
        xMap.insert({x,cows[i]});
        yMap.insert({y,cows[i]}); 
        if(c=='N'){
            northX.push_back(x);
        }else{
            eastY.push_back(y);
        }
    }
    sort(northX.begin(),northX.end());
    sort(eastY.begin(),eastY.end());
    maxD = vector<ll>(n,-1);
    found = vector<bool>(n,false);
    for(int i = 0; i < n; i++){
        findMax(i);
    }
    for(int i = 0; i < n; i++){
        cout<<(maxD[i]>0?to_string(maxD[i]):"Infinity")<<"\n";
    }
}