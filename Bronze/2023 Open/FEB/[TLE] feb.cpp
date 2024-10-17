#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int n;
string s;
vector<int> p;
unordered_set<int> ps;
void findAll(int bCnt, int eCnt, int score, int i){
    score+=bCnt>=2 || eCnt>=2;
    if(i==n){
        if(ps.find(score)==ps.end()){
            ps.insert(score);
            p.push_back(score);
        }
        return;
    }
    if(s[i]=='B' || s[i]=='F'){
        findAll(bCnt+1,0,score,i+1);
    }
    if(s[i]=='E' || s[i]=='F'){
        findAll(0,eCnt+1,score,i+1);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    findAll(0,0,0,0);
    sort(p.begin(),p.end());
    cout<<p.size()<<"\n";
    for(int i = 0; i < p.size(); ++i){
        cout<<p[i]<<"\n";
    }
}