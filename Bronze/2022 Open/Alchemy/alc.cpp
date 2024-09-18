#include <iostream>
#include <vector>
#define NMAX 105
using namespace std;
int supply[105]{};
vector<vector<int>> recipe;
bool makeMetal(int m){
    if(supply[m]>0){
        --supply[m];
        return 1;
    }
    if(recipe[m].empty()){return 0;}
    bool canMake = 1;
    for(int i = 0; i < recipe[m].size(); ++i){
        if(!makeMetal(recipe[m][i])){
            return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n;
    recipe.assign(n+1,vector<int>());
    for(int i = 1; i <= n; ++i){
        cin>>supply[i];
    }
    cin>>k;
    for(int i = 0; i < k; ++i){
        int m, s; cin>>m>>s;
        while(s--){
            int part; cin>>part;
            recipe[m].push_back(part);
        }
    }
    int cnt = 0;
    while(makeMetal(n))
        ++cnt;
    cout<<cnt<<"\n";
}