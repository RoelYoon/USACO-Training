#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> parent;
vector<bool> visited;
vector<int> potionCnt;
vector<bool> isLeaf;
int traversals = 0;
void root(int head){
    visited[head]=1;
    bool leaf=1;
    for(int i = 0; i < graph[head].size(); ++i){
        if(!visited[graph[head][i]]){
            leaf=0;
            parent[graph[head][i]]=head;
            root(graph[head][i]);
        }
    }
    if(leaf){
        ++traversals;
        isLeaf[head]=1;
    }
}
int ans = 0;
int collect(int head, int collection){
    visited[head]=1;
    int collected=0;
    for(int i = 0; i < graph[head].size(); ++i){
        if(!visited[graph[head][i]]){
            collected+=collect(graph[head][i],collection+potionCnt[head]-collected);
        }
    }
    if(isLeaf[head] && collection+potionCnt[head]>0){
        //validate collection
        ++ans;
        return max(1-(potionCnt[head]),0);
    }
    return max(collected-(potionCnt[head]),0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    graph.resize(n);
    parent.resize(n);
    potionCnt.assign(n,0);
    isLeaf.assign(n,0);
    vector<int> potions(n);
    for(int i = 0; i < n; ++i){
        cin>>potions[i]; 
        --potions[i];
    }
    for(int i = 0; i < n-1; ++i){
        int a,b; cin>>a>>b; 
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.assign(n,0);
    parent[0]=-1;
    root(0);
    for(int i = 0; i < traversals; ++i)
        ++potionCnt[potions[i]];
    visited.assign(n,0);
    collect(0,0);
    cout<<ans<<"\n";
}
/*
10
1 4 3 2 6 7 3 8 9 10
1 2
1 3
3 4
3 5
4 6
5 7
1 9 
1 10
3 8

10
6 6 6 6 6 1 1 1 1 1
1 2
1 3
3 4
3 5
4 6
5 7
1 9 
1 10
3 8

10 
2 3 4 5 6 7 8 9 10 1
1 2
2 3
3 4
4 5
5 6
1 7
7 8
8 9
9 10
*/