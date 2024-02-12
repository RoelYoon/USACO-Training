#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n;
unordered_map<int,int> coordMap;
int score(vector<int> &bales, int startBale){
    int dist = 1; 
    int score = 0;
    queue<int> explosions;
    queue<int> radius; 
    vector<bool> exploded(n,false);
    explosions.push(startBale);
    radius.push(1);
    while(!explosions.empty()){
        int start  = explosions.front();
        int range = radius.front();
        explosions.pop();
        radius.pop();
        if(exploded[start]){continue;}
        exploded[start]=true;
        score++;
        for(int i = 1; i <= range; i++){
            if(coordMap.find(bales[start]+i)!=coordMap.end()){
                explosions.push(coordMap.find(bales[start]+i)->second);
                radius.push(range+1);
            }
            if(coordMap.find(bales[start]-i)!=coordMap.end()){
                explosions.push(coordMap.find(bales[start]-i)->second);
                radius.push(range+1);
            }
        }
    }
    return score;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin>>n;
    vector<int> bales(n);
    for(int i = 0; i < n; i++){
        cin>>bales[i];
        coordMap.insert({bales[i],i});
    }
    int maxScore = 0; 
    for(int i = 0; i < n; i++){
        maxScore=max(maxScore,score(bales,i));
    }
    cout<<maxScore<<"\n";
}
