#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; 
    while(t--){
        unordered_map<char,char> identity;
        unordered_map<char,int> reverseCount; 
        unordered_set<char> reverseSet;
        unordered_map<char,int> dupeCount;
        int count = 0;
        string s, goal; cin>>s>>goal;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char,int>::iterator it = dupeCount.find(s[i]);
            if(it==dupeCount.end()){
                dupeCount.insert({s[i],1});
            }else{
                (it->second)++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            bool identitySet=identity.find(s[i])!=identity.end();
            char c = !identitySet ? s[i] : identity.find(s[i])->second;
            if(c!=goal[i]){
                //change needed
                if(identitySet){
                    cout<<-1<<"\n";
                    goto impossible;
                }
                identity.insert({s[i],goal[i]});
                //if(identity.find(goal[i])!=identity.end()){
                    if(reverseSet.find(s[i])==reverseSet.end()){
                        unordered_map<char,int>::iterator it = reverseCount.find(goal[i]);
                        if(it!=reverseCount.end()){
                            (it->second)++;
                        }else{
                            reverseCount.insert({goal[i],1});
                        }
                        reverseSet.insert({s[i]});
                    }
                //}
                unordered_map<char,int>::iterator it = reverseCount.find(c);
                if(it!=reverseCount.end()){
                    count+=(it->second)*(dupeCount.find(c)->second);
                    it->second = 0;
                }
                count++;
            }else if(identitySet){
                count++;
            }
        }
        cout<<count<<"\n";
        impossible:continue;
    }
}
