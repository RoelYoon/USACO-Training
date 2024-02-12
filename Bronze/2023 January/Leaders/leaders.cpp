#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector> 
#define MAX 100005
using namespace std;
int n;
string s; 
int lists[MAX];
int cnt = 0;
int GCount, HCount; 
int countCow(int cow){
    int returnCnt = 0; 
    char c = s[cow];
    for(int i = cow; i <= lists[cow]-1; i++){
        if(s[i]==c){
            returnCnt++; 
        }
    }
    return returnCnt; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n>>s; 
    for(int i = 0; i < n; i++)
        cin>>lists[i];
    int GFirst = s.find('G');
    GCount = count(s.begin(),s.end(),'G');
    int HFirst = s.find('H');
    HCount = count(s.begin(),s.end(),'H');
    vector<int> possibleG, possibleH; 
    if(countCow(GFirst)==GCount)
        possibleG.push_back(GFirst);
    if(countCow(HFirst)==HCount)
        possibleH.push_back(HFirst);
    vector<int> *origin = (!possibleG.empty()?&possibleG:&possibleH);
    vector<int> *other = (possibleG.empty()?&possibleG:&possibleH); 
    unordered_set<int> leads; 
    leads.insert({(*origin)[0]});
    if(!(*other).empty()){
        leads.insert({(*other)[0]});
        int original = (*other)[0]; 
        for(int i = original-1; i >= 0; i--){
            if(lists[i]-1>=original){
                if(leads.find(i)==leads.end()){
                (*origin).push_back(i);
                leads.insert({i}); 
                }
            }
        }
    }
    int original = (*origin)[0]; 
    for(int i = original-1; i >= 0; i--){
        if(lists[i]-1>=original){
            if(leads.find(i)==leads.end()){
            (*other).push_back(i);
            leads.insert({i});
            }
        }
    }
    cout<<(*origin).size()*(*other).size()<<"\n";
}