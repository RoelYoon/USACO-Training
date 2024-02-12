/*
ID: roelyoon
TASK: numtri
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int n;
int mem[1005][1005];
vector<vector<int>> triangle; 
int DFS(int row, int col){
    if(row==n-1){return triangle[row][col];}
    if(mem[row][col]!=-1){return mem[row][col]+triangle[row][col];}
    int DFS1 = DFS(row+1,col);
    int DFS2 = DFS(row+1,col+1); 
    mem[row][col] = max(DFS1,DFS2);
    return mem[row][col] + triangle[row][col];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>n;
    triangle = vector<vector<int>>(n); 
    for(int i = 1; i <= n; i++){
        for(int k = 0; k < i; k++){
            int temp; cin>>temp;
            triangle[i-1].push_back(temp);
            mem[i-1][k]=-1;
            mem[i-1][k+1]=-1;
        }
    }
    cout<<DFS(0,0)<<"\n";
    return 0;
}