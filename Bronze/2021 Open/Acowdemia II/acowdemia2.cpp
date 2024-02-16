#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void seniorDFS(vector<string> &answers,vector<vector<int>> &equalGraph, vector<bool> &visited, int &origin, int head){
    if(visited[head]){return;}
    visited[head]=true;
    for(int i = 0; i < answers[head].size(); i++){
        if(answers[head][i]=='1' && answers[origin][i]=='?'){
            answers[origin][i]='1';
            answers[i][origin]='0';
        }
    }
    for(int i = 0; i < equalGraph[head].size(); i++){
        seniorDFS(answers,equalGraph,visited,origin,equalGraph[head][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k; cin>>k>>n;
    unordered_map<string,int> name2id; 
    unordered_map<int, string> id2name;
    unordered_map<int,int> id2order;
    vector<string> names;
    for(int i = 0; i < n; i++){
        string temp; cin>>temp;
        name2id.insert({temp,i});
        id2name.insert({i,temp});
        names.push_back(temp);
    }
    sort(names.begin(),names.end());
    for(int i = 0; i < n; i++){
        id2order.insert({name2id.find(names[i])->second,i});
    }
    vector<string> answers(n);
    vector<vector<int>> equalGraph(n);
    for(int i = 0; i < n; i++){
        string ans = "";
        for(int j = 0; j < n; j++){
            ans+=(i==j?"B":"?");
        }answers[i]=ans;
    }
    for(int i = 0; i < k; i++){
        vector<int> pub(n);
        for(int j = 0; j < n; j++){
            string temp; cin>>temp;
            int id = name2id.find(temp)->second;
            for(int p = 0; p < pub.size(); p++){
                if(id2order.find(id)->second < id2order.find(pub[p])->second){
                    //cur id is senior of id p
                    answers[id][pub[p]]='1';
                    answers[pub[p]][id]='0';
                }
                if(answers[id][pub[p]]!='?'){
                    equalGraph[id].push_back(pub[p]);
                }
            }
            pub.push_back(name2id.find(temp)->second);
        }
    }
    for(int i = 0; i < n; i++){
        vector<bool> visited(n,false);
        seniorDFS(answers,equalGraph,visited,i,i);
    }
    for(int i = 0; i < n; i++){
        cout<<answers[i]<<"\n";
    }
}