#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x; cin>>n>>m>>x; --x;
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(int i = 0; i < n; ++i)
        dist[i][i]=0;
    for(int i = 0; i < m; ++i){
        int a,b,w; cin>>a>>b>>w; --a, --b;
        dist[a][b]=w;
    }
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    int maxDist = 0;
    for(int i = 0; i < n; ++i){
        int d = dist[i][x]+dist[x][i];
        maxDist=max(maxDist,(int)(d>1e9?-1e9:d));
    }
    cout<<maxDist<<"\n";
}