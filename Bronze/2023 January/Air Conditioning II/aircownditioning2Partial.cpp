#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define ll long long
using namespace std;
struct Cow{
    int start;
    int end; 
    int condition; 
};
struct Conditioner{
    int start;
    int end; 
    int p; 
    int cost; 
    bool used=false; 
};
Cow cows[20];
vector<Conditioner> conds; 
int stalls[100] = {};
int n,m;
ll minCost = 0; 
bool inRange(Conditioner c, int x){
    return (c.start<=x && x<=c.end); 
}
void DFSOptimal(int condition, unordered_set<int> &included, vector<int> condSet,vector<int> &condsUsed, vector<int>condsPath, int &mCost,int cost){
    if(condition<=0){
        if(cost<mCost){
            mCost = cost;
            condsUsed=condsPath;
        }
        return; 
    }
    for(int i = 0; i < condSet.size();i++){
        if(included.find(condSet[i])==included.end()){
            included.insert({condSet[i]});
            condsPath.push_back(condSet[i]);
            DFSOptimal(condition-conds[condSet[i]].p, included, condSet,condsUsed,condsPath,mCost,cost+conds[condSet[i]].cost);
            included.erase(condSet[i]); 
            condsPath.pop_back();
        }
    }
}
void findCondsToUse(int x, int &cost, vector<int> &condsUsed){
    vector<int> condSet; 
    for(int i = 0; i < m; i++){
        if(!conds[i].used && inRange(conds[i],x)){
            condSet.push_back(i); 
        }
    }
    unordered_set<int> included;
    DFSOptimal(stalls[x],included,condSet,condsUsed,vector<int>(),cost,0); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    conds = vector<Conditioner>(m); 
    for(int i = 0; i < n; i++){
        cin>>cows[i].start>>cows[i].end>>cows[i].condition;
        cows[i].start--; cows[i].end--;
        for(int j = cows[i].start; j <= cows[i].end; j++)
            stalls[j] = cows[i].condition; 
    }
    for(int i = 0; i < m; i++){
        cin>>conds[i].start>>conds[i].end>>conds[i].p>>conds[i].cost;
        conds[i].start--; conds[i].end--;
    }
    sort(conds.begin(),conds.end(),[](const Conditioner &a, const Conditioner &b){return a.cost < b.cost;});
    for(int i = 0; i < 100; i++){
        if(stalls[i]>0){
            vector<int> condsUsed;
            int cost = 1e9; 
            findCondsToUse(i, cost, condsUsed); 
            minCost+=cost;
            for(int j = 0; j < condsUsed.size(); j++){
                Conditioner c  = conds[condsUsed[j]]; 
                conds[condsUsed[j]].used=true;
                for(int k = c.start; k <= c.end; k++)
                    stalls[k]-=c.p; 
            }
        }
    }
    cout<<minCost<<"\n";
}
