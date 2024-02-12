#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
int cost(string &s, int pos){
    int left = pos-1; 
    int right = pos+1; 
    return (left) + (s.size()-1-right) + (s[left]=='O' ? 1 : 0) + (s[right]=='M' ? 1 : 0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        string s; cin>>s; 
        vector<int> Opositions; 
        for(int j = 0; j < s.size(); j++){
            if(s[j]=='O' && j>0 && j<s.size()-1){
                Opositions.push_back(j); 
            }
        }
        if(Opositions.empty()){ 
            cout<<"-1\n"; 
            continue;
        }
        int minCost = 1e9; 
        for(int j = 0; j < Opositions.size(); j++){
            int c = cost(s,Opositions[j]);
            minCost = (minCost < c ? minCost:c);
        }
        cout<<minCost<<"\n";
    }
}
