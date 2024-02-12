#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    cin>>n;
    int shuffle[105];
    int origin[105];
    for(int i = 0; i < n; i++){
        cin>>shuffle[i]; shuffle[i]--;
        origin[shuffle[i]]=i;
    }
    unordered_map<string, int> orderMap;
    for(int i = 0; i < n; i++){
        string id;
        cin>>id;
        orderMap.insert({id,i});
    }
    for(int i = 0; i < 3; i++){
        for(unordered_map<string,int>::iterator it=orderMap.begin();
        it!=orderMap.end(); it++){
            it->second = origin[it->second];
        }
    }
    vector<pair<string,int>> sortedOrder;
    for(unordered_map<string,int>::iterator it=orderMap.begin();
    it!=orderMap.end(); it++){
        sortedOrder.push_back(*it);
    }
    sort(sortedOrder.begin(),sortedOrder.end(),[](const pair<string,int> &a, const pair<string,int> &b){return a.second<b.second;});
    for(int i = 0; i < n; i++){
        cout<<sortedOrder[i].first<<"\n";
    }
}
