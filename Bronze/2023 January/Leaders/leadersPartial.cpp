/*
ID: roelyoon
TASK: name
LANG: C++                 
*/
#include <iostream>
#include <vector>
using namespace std;
inline bool checkIfLeader(char breed,string &line, vector<int> &ranges,int &cow,int &H,int &G){
    int count=0;
    int j=cow-1;
    for(int i = cow; i<=ranges[cow]; i++){
        if(breed=='H' && line[i]=='H'){
            count++;
        }
        else if(breed=='G' && line[i]=='G'){
            count++;
        }
        if(j>=0){
            if(breed=='H' && line[j]=='H'){
                break;
            }
            else if(breed=='G' && line[j]=='G'){
                break;
            }
        }
        j--;
    }
    if(breed=='H' && count==H){
        return true; 
    }else if(breed=='G' && count==G){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int pairs = 0; 
    string line;
    cin>>n>>line;
    vector<int> ranges(n);
    int HLeaders = 0;
    int GLeaders = 0;
    vector<bool> HLeader(n,false);
    vector<bool> GLeader(n,false); 
    int HCount=0;
    int GCount=0;
    for(int i = 0; i < n; i++){
        cin>>ranges[i];
        ranges[i]--;
        //multi-tasking
        if(line[i]=='H'){HCount++;}
        else if(line[i]=='G'){GCount++;}
    }
    for(int i = 0; i < n; i++){
        if(checkIfLeader(line[i],line,ranges,i,HCount,GCount)){
            if(line[i]=='H'){
                HLeader[i]=true;
                HLeaders++;
            }
            else if(line[i]=='G'){
                GLeader[i]=true;
                GLeaders++;
            }
        }
    }
    pairs+=HLeaders*GLeaders;
    for(int i = 0; i < n; i++){
        if(!HLeader[i] && !GLeader[i]){
            char breed = line[i];
            for(int j = i; j<=ranges[i]; j++){
                if(breed=='H'){
                    if(GLeader[j]){
                        pairs++;
                    }
                }
                if(breed=='G'){
                    if(HLeader[j]){
                        pairs++;
                    }
                }
            }
        }
    }
    cout<<pairs;
}


//g++ -std=c++17 leaders.cpp