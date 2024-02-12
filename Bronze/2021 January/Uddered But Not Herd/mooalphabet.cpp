#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin>>s; 
    string heard; cin>>heard; 
    unordered_map<char,int> alphabetMap; 
    for(int i = 0; i < s.size(); i++)
        alphabetMap.insert({s[i],i});
    int count = 1;
    int lastPos = alphabetMap.find(heard[0])->second; 
    for(int i = 1; i < heard.size(); i++){
        if(alphabetMap.find(heard[i])->second<=lastPos){
            count++;
        }
        lastPos=alphabetMap.find(heard[i])->second;
    }
    cout<<count<<"\n";
}
