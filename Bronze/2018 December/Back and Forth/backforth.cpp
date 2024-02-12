#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> mem;
void generate(vector<int> b1, vector<int> b2, bool t, int m,int d){
    if(d==4){
        mem.insert({m});
        return;
    }
    if(t){
        for(int i = 0; i < b1.size(); i++){
            if(b1[i]!=0){
                b1[i]--;
                b2[i]++;
                generate(b1,b2,!t,m-i,d+1);
                b1[i]++;
                b2[i]--;
            }
        }
    }else{
        for(int i = 0; i < b2.size(); i++){
            if(b2[i]!=0){
                b2[i]--;
                b1[i]++;
                generate(b1,b2,!t,m+i,d+1);
                b2[i]++;
                b1[i]--;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    vector<int> b1(105), b2(105);
    int m=0;
    for(int i = 0; i < 10; i++){
        int temp; cin>>temp;
        b1[temp]++;
    }
    for(int i = 0; i < 10; i++){
        int temp; cin>>temp;
        b2[temp]++;
    }
    generate(b1,b2,1,1000,0);
    cout<<mem.size()<<"\n";
}