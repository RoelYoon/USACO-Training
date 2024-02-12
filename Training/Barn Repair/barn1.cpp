/*
ID: roelyoon
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("barn1.in","r",stdin);
    //freopen("barn1.out","w",stdout);
    int m,s,c; cin>>m>>s>>c;
    array<bool,205> stalls = {}; 
    for(int i = 0; i < c; i++){
        int pos; cin>>pos;
        stalls[pos] = true; 
    }
    if(m>=c){cout<<c<<"\n"; return 0;}
    vector<int> segments;
    int lastCow=-1; 
    for(int i = 1; i <= s; i++){
        if(stalls[i]){
            if(lastCow==-1){lastCow=i;continue;}
            segments.push_back(i-lastCow-1);
            lastCow=i;
        }
    }
    sort(segments.begin(),segments.end());
    int covered = c; 
    int boards = c; 
    int i = 0;
    while(boards > m){
        covered+=segments[i];
        boards--;
        i++;
    }
    cout<<covered<<"\n";
}