#include <iostream>
#include <vector>
using namespace std;
struct Relation{
    int node; 
    int additionalTime; 
    Relation(int nd, int time):node(nd),additionalTime(time){}
};
void calculate(vector<vector<Relation>> &graph, vector<int> &times, vector<bool> &visited, int head){
    if(visited[head]){
        return;
    }
    visited[head]=true;
    for(Relation r : graph[head]){
        times[head] = times[r.node]+r.additionalTime > times[head] ? times[r.node]+r.additionalTime : times[head]; 
        calculate(graph,times,visited,r.node); 
        times[head] = times[r.node]+r.additionalTime > times[head] ? times[r.node]+r.additionalTime : times[head]; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin>>n>>m>>c; 
    vector<int> times(n);
    vector<vector<Relation>> graph(n); 
    vector<bool> visited(n,false);
    for(int i = 0; i < n; i++){
        cin>>times[i];
    }
    for(int i = 0; i < c; i++){
        int a,b,x; 
        cin>>a>>b>>x; a--; b--;
        graph[b].push_back(Relation(a,x));
    }
    for(int i = 0; i < n; i++){
        calculate(graph,times,visited,i);
    }
    for(int time : times){
        cout<<time<<"\n"; 
    }
}
//g++ -std=c++17 abc.cpp   
//prob 18780