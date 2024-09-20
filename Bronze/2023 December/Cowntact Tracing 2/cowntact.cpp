#include <iostream>
#include <vector>
using namespace std;
struct Blob{
    int sz;
    int start;
    int end;
    bool edge;
    Blob(){}
    Blob(int s, int e):sz(s),end(e),edge(0){
        start=end-(sz-1);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<Blob> bs;
    string s; cin>>s;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i]=='1'){
            ++cnt;
        }else if(cnt>0){
            bs.emplace_back(cnt,i-1);
            cnt=0;
        }
    }if(cnt>0) bs.emplace_back(cnt,n-1);
    if(bs.empty()){cout<<"0\n"; return 0;}
    bs[0].edge = s[bs[0].start] == '1';
    bs[bs.size()-1].edge = s[bs[bs.size()-1].end] == '1';
    if(bs.size()==1 && bs[0].edge){
        cout<<"1\n";
        return 0;
    }
    int maxNights = 1000000000; //day FJ reports on the sickness
    for (int i = 0; i < bs.size(); ++i) {
        if (bs[i].start == 0 || bs[i].end == n-1) {
            maxNights = min(maxNights,bs[i].sz);
        } else {
            maxNights = min(maxNights,(bs[i].sz+1)/2);
        }
    }
    int minCows = 0;
    for (int i = 0; i < bs.size(); ++i)
        minCows += (bs[i].sz + 2*maxNights-2)/(2*maxNights-1);
    cout<<minCows<<"\n";
}