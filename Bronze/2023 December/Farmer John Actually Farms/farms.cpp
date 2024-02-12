#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n; 
struct Plant{
    ll height;
    ll growth;
    ll other;
    int id;
    Plant(){}
    void grow(){
        height+=growth;
    }
};
bool impossible(vector<Plant> &plants, int plant){
    int tallerCount = 0;
    for(int i = 0; i < n; i++){
        if(i!=plant){
            if(!(plants[i].height<plants[plant].height || plants[plant].growth > plants[i].growth || plants[plant].growth==plants[i].growth && plants[plant].height > plants[i].height)){
                tallerCount++;
            }
            if(tallerCount==plants[plant].other){
                return false;
            }
        }
    }
    return true;
}
int tries =0 ;
int failurePlant=-1;
bool satisfied(vector<Plant> &plants, bool& possible){
   // static int failurePlant=-1;
    //static int tries = 0;
    for(int i = 0; i < n; i++){
        if(i<n-1-plants[i].other){
            if(plants[i].id==failurePlant){
                tries++;
            }
            else{
                failurePlant=plants[i].id;
                tries=0;
            }
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<Plant> plants(n);
        for(int i = 0; i < n; i++){
            cin>>plants[i].height;
            plants[i].id=i;
        }
        for(int i = 0; i < n; i++){
            cin>>plants[i].growth;
        }
        for(int i = 0; i < n; i++){
            cin>>plants[i].other;
        }
        sort(plants.begin(),plants.end(),[](Plant& a, Plant &b){return a.height<b.height;});
        bool possible = true;
        int days = 0;
        int notChangeCount=0;
        tries=0;
        failurePlant=-1;
        while(!satisfied(plants,possible)){
            for(int i = 0; i < n; i++){
                plants[i].grow();
            }
            bool changed=false;
            sort(plants.begin(),plants.end(),[&changed](Plant& a, Plant &b){if(!changed && a.height<b.height){changed=true;}return a.height<b.height;});
            if(!changed){
                notChangeCount++;
            }
            if(notChangeCount>10 || tries>1000){
                possible=false;
            }
            days++;
            if(!possible){break;}
        }
        if(possible){
            cout<<days<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}
