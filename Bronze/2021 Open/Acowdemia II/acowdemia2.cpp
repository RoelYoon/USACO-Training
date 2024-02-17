#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>n;
    vector<string> names(n);
    vector<string> nameSorted(n);
    unordered_map<string, int> order;
    unordered_map<string, int> nameMap;
    for(int i = 0; i < n; i++){
        cin>>names[i];
        nameSorted[i]=names[i];
        nameMap.insert({names[i],i});
    }
    sort(nameSorted.begin(),nameSorted.end());
    for(int i = 0; i < n; i++){
        order.insert({nameSorted[i],i});
    }
    vector<string> ans(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[i]+=(i==j?"B":"?");
        }
    }
    vector<vector<string>> entries(k);
    for(int i = 0; i < k; i++){
        vector<string> entry(n);
        for(int j = 0; j < n; j++){
            cin>>entry[j];
        }
        int lastBroken = -1;
        for(int j = 1; j < n; j++){
            if(order[entry[j]] < order[entry[j-1]]){
                //alphabetical ordering broken
                lastBroken = j-1;
            }
            for(int k = lastBroken; k >= 0; k--){
                ans[nameMap[entry[j]]][nameMap[entry[k]]]='1';
                ans[nameMap[entry[k]]][nameMap[entry[j]]]='0';
            }
        }
        entries[i] = entry;
    }
    
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<"\n";
    }
}