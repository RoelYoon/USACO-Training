/*
ID: roelyoon
TASK: wormhole
LANG: C++                 
*/
#include <iostream>
using namespace std; 
struct Portal{
    int x;
    int y;
};
int n;
int cnt = 0; 
Portal portals[12];
int xNext[12]; 
bool terminates(int pairs[12], int start){
    int cur = start; 
    int step = 0; 
    bool walking = true; 
    while(step < 10*n){
        if(walking && xNext[cur]==-1){return true;}
        if(walking){
            cur = xNext[cur]; 
        }else{
            cur = pairs[cur];
        }
        walking=!walking;
        step++;
    }
    return false;
}
bool isCyclic(int pairs[12]){
    for(int i = 0; i < n; i++){
        if(!terminates(pairs,i)){
            return true; 
        }
    }
    return false;
}
void calculatePairs(int pairs[12],int pairSet){
    if(pairSet == n/2){
        cnt+=isCyclic(pairs);
        return;
    }
    int i; 
    for(i = 0; i<n; i++){
        if(pairs[i]==-1){
            break;
        }
    }
    if(pairs[i]==-1){
        for(int j = i+1; j<n; j++){
            if(pairs[j]==-1){
                pairs[i]=j;
                pairs[j]=i;
                calculatePairs(pairs,pairSet+1);
                pairs[i]=-1;
                pairs[j]=-1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout); 
    cin>>n; 
    for(int i = 0; i < n; i++)
        cin>>portals[i].x>>portals[i].y;
    for(int i = 0; i < n; i++){
        xNext[i]=-1;
        int minDist = 1e9+5; 
        for(int j = 0; j < n; j++){
            if(portals[i].y == portals[j].y && portals[j].x > portals[i].x && portals[j].x-portals[i].x < minDist){
                xNext[i] = j;
                minDist = portals[j].x-portals[i].x; 
            }
        }
    }
    {
        int pairs[12]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        calculatePairs(pairs,0); 
    }
    cout<<cnt<<"\n"; 
}