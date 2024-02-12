/*
ID: roelyoon
TASK: namenum
LANG: C++                 
*/
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;
unordered_set<string> dict;
unordered_map<char,array<char,3>> mapping; 
vector<string> validNames; 
void generateNames(string &serial,int place, string name){
    if(name.size()==serial.size() && dict.find(name)!=dict.end()){validNames.push_back(name);}
    if(place==serial.size()){return;}
    array<char,3> letters = mapping.find(serial[place])->second;
    for(char c : letters)
        generateNames(serial,place+1,name+c);
}
int main(){
    ifstream dictFile("dict.txt");
    string dictName; 
    while(dictFile>>dictName)
        dict.insert(dictName);
    ifstream in("namenum.in");
    ofstream out("namenum.out");
    mapping={{'2',{'A','B','C'}},{'3',{'D','E','F'}},{'4',{'G','H','I'}},{'5',{'J','K','L'}},{'6',{'M','N','O'}},{'7',{'P','R','S'}},{'8',{'T','U','V'}},{'9',{'W','X','Y'}}};
    string serial; in>>serial;
    generateNames(serial,0,"");
    for(string name : validNames)
        out<<name<<"\n";
    if(validNames.size()==0)
        out<<"NONE\n";
    return 0;
} 