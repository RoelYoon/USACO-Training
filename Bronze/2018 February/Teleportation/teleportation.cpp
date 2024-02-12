#include <iostream>
using namespace std;
int main(){
    freopen("teleport.in","r",stdin);
    freopen("teleport.out","w",stdout);
    int start, end, p1, p2;
    cin>>start>>end>>p1>>p2;
    cout<<min(abs(p1-start)+abs(p2-end),min(abs(p2-start)+abs(p1-end),abs(start-end)))<<"\n";
}