#include <iostream>
using namespace std;
int x,y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    cin>>x>>y; 
    if(x==y){cout<<0<<"\n"; return 0;}
    bool pos=1;
    long long dist=0;
    for(long long i = 1; i < 1000000000000; i*=2){
        dist+=abs(x-(x+(!pos?i/2:-i/2)))+i;
        long long f = x+(pos?i:-i);  
        if(pos && y<=f && y>x || !pos && y>=f && y<x){
            dist-=abs(f-y);
            break;
        }
        pos=!pos;
    }
    cout<<dist<<"\n";
}