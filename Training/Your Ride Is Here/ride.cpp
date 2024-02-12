/*
ID: roelyoon
TASK: ride
LANG: C++                 
*/
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    //freopen("ride.in","r",stdin);
    //freopen("ride.out","w",stdout);
    string a, b;
    int comet=1,group=1;
    cin >> a >> b;
    for(char c : a){
        comet*=(c-64);
    }
    for(char c : b){
        group*=(c-64);
    }
    int m = comet%47;
    if(group%47==m){cout<<"GO\n";}else{cout<<"STAY\n";}
    return 0;
}