#include <iostream>
#include <unordered_set>
#include <vector>
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
};
int n,m;  
int stalls[100];
Cow cows[20]; 
vector<Conditioner> conds; 
int minCost = 2e9;
void set(int arr[100],int condID){
    Conditioner cond = conds[condID];
    for(int i = cond.start; i <= cond.end; i++)
        arr[i]-=cond.p;
}
void set(int arr[100],Cow &cow){
    for(int i = cow.start; i <= cow.end; i++)
        arr[i]=cow.condition;
}
bool condMet(int &included){
    int stallsCopy[100]; for(int i = 0; i < 100; i++){stallsCopy[i]=stalls[i];}
    for(int i = 0; i < m; i++)
        if(included & (1<<i))
            set(stallsCopy,i); 
    for(int i = 0; i < 100; i++)
        if(stallsCopy[i]>0)
            return false; 
    return true; 
}
void bruteDFS(int included,unordered_set<int> &mem, vector<Conditioner> &conds, int cost, int cond){
    if(mem.find(included)!=mem.end()){return;}
    if(condMet(included)){
        minCost=(minCost < cost) ? minCost : cost; 
        return; 
    }
    mem.insert({included});
    for(int i = 0; i < m; i++)
        if(!(included & (1<<i)))
            bruteDFS(included | (1<<i),mem,conds,cost+conds[i].cost,i);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>cows[i].start>>cows[i].end>>cows[i].condition;
        cows[i].start--; cows[i].end--; 
        set(stalls,cows[i]);
    }
    conds = vector<Conditioner>(m); 
    for(int i = 0; i < m; i++){
        cin>>conds[i].start>>conds[i].end>>conds[i].p>>conds[i].cost;
        conds[i].start--; conds[i].end--;
    } 
    unordered_set<int> mem; 
    bruteDFS(0, mem,conds, 0,0); 
    cout<<minCost<<"\n";
}
