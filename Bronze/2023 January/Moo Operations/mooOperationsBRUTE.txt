/*Brute force with recursive search. Times out after test case 5*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool checkString(string &str){
    string pattern="MOO";
    int ind = 0; 
    for(int i = 0; i < str.size(); i++){
        if(str[i]!=pattern[ind])
            return false;
        ind=(ind+1)%3; 
    }
    return true;
}
void search(string str,unordered_map<string,int>&mem,int& minCount,int count){
    if(count>=minCount || str.size()<3 || mem.find(str)!=mem.end() && mem.find(str)->second<count){return;}
    if(str[0]=='M' && str[str.size()-1]=='O' && str.size()%3==0 && checkString(str)){
        if(count<minCount){minCount=count;}
        return; 
    }
    mem.insert({str,count});
    //operation 1.1
    if(str[0]=='O'){
        str[0]='M';
        search(str,mem,minCount,count+1);
        str[0]='O';
    }
    //operation 1.2
    if(str[str.size()-1]=='M'){
        str[str.size()-1]='O';
        search(str,mem,minCount,count+1);
        str[str.size()-1]='M';
    }
    //operation 2.1
    search(str.substr(1),mem,minCount,count+1);
    //operation 2.2 
    search(str.substr(0,str.size()-1),mem,minCount,count+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    unordered_map<string,int> mem; 
    for(int i = 0; i < n; i++){
        string str; 
        cin>>str;
        int minCount=101;
        search(str,mem,minCount,0);
        cout<<(minCount==101?-1:minCount)<<"\n"; 
    }
}