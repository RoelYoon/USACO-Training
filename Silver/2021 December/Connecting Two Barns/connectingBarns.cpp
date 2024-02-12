#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> 
#include <math.h>
using namespace std;
int n,m;
void findConnections(vector<vector<int>> &graph, vector<int> &connections, vector<bool> &visited, int head){
    if(visited[head]){return;}
    visited[head]=true;
    connections.push_back(head);
    for(int connection : graph[head])
        findConnections(graph,connections,visited,connection);
}
int dist(int a, vector<int> &b){
    int ind = lower_bound(b.begin(),b.end(),a) - b.begin();
    ind = ind==-1 ? b.size()-1 : ind;
    return abs(b[ind]-a) < (ind!=0 ? abs(b[ind-1]-a) : n) ? abs(b[ind]-a) : (ind!=0 ? abs(b[ind-1]-a) : n);
}
bool ascending(vector<int> &a, vector<int> &b, int low, int high){
    if(low<0){return false;}
    if(high>=a.size()){return true;}
    int leftVal = dist(a[low],b);
    int rightVal = dist(a[high],b);
    return leftVal < rightVal; 
}
int findMinDif(vector<int> &a, vector<int> &b){
    int minDif=n+1; 
    int low=0, high=a.size()-1;
    while(1){
        int mid = (low+high)/2;
        if(low>=high){
            minDif = min(minDif,dist(a[mid],b));
            break;
        }
        minDif=min(minDif,dist(a[mid],b));
        if(ascending(a,b,mid-1,mid+1)){high=mid;}
        else{low=mid+1;}
    }
    return minDif; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> graph(n);
        for(int i = 0; i < m; i++){
            int a,b; cin>>a>>b; a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<vector<int>> connections(n);
        vector<bool> visited(n,false);
        findConnections(graph,connections[0],visited,0); 
        sort(connections[0].begin(),connections[0].end());
        if(visited[n-1]){connections[n-1].push_back(n-1);}
        findConnections(graph,connections[n-1],visited,n-1); 
        sort(connections[n-1].begin(),connections[n-1].end());
        for(int i = 1; i < n-1; i++){
            if(!visited[i]){
                findConnections(graph,connections[i],visited,i); 
                sort(connections[i].begin(),connections[i].end());
            }
        }
        long long minCost = pow(findMinDif(connections[0],connections[n-1]),2);
        for(int i = 1; i < n-1; i++)
            if(!connections[i].empty())
                minCost = min(minCost, (long long)pow(findMinDif(connections[i],connections[0]),2) + (long long)pow(findMinDif(connections[i],connections[n-1]),2));
        cout<<minCost<<"\n";
    }
    return 0;
}