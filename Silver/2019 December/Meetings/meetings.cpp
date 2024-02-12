/*
ID: roelyoon
TASK: name
LANG: C++                 
*/
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
struct cow{
    int weight=0;
    int location=0;
    int direction=0; 
};
int timeToReachX(vector<cow> &line,int cowIndex, ll x, int time){
    cow c = line[cowIndex]; 
    if(x==c.location){
        //reached
        return time;
    }
    if(x<c.location){
        //destination is to the left
        if(c.direction==-1){
            //in the right direction
            if(cowIndex==0){
                
            }
        }else if(c.direction==1){
            //in the wrong direction

        }
    }else{
        //destination is to the right
        if(c.direction==1){
            //in the right direction

        }else if(c.direction==-1){
            //in the wrong direction

        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ll n, l; 
    cin >>  n >> l;
    l--;
    vector<cow> line(n);
    for(int i=0; i<n; i++){
        int w,x,d;
        cin>>w>>x>>d;
        line[i].weight=w;
        line[i].location=x;
        line[i].direction=d;
    }
    sort(line.begin(), line.end(), [](const cow &a, const cow &b) -> bool {return (a.location < b.location);});
    for(int i=0; i<n; i++){
        cout<<line[i].location;
    }
    /*
    lazy method: keep track of time
    make function for updating only one cow without changing array
    */
}