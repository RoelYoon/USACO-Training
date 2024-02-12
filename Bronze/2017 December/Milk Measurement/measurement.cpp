#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Log{
    int day;
    string cow;
    int change;
    Log(){cin>>day>>cow>>change;}
};
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    cin>>n;
    vector<Log> logs(n);
    sort(logs.begin(),logs.end(),[](const Log& a, const Log& b){return a.day<b.day;});
    unordered_map<string, int> production={{"Bessie",7},{"Elsie",7},{"Mildred",7}}; 
    unordered_set<string> displayedCows({"Bessie","Elsie","Mildred"});
    int maxProduction = 7;
    int count = 0;
    for(int i = 0; i < n; i++){
        //create a copy of the current display for comparison later
        unordered_set<string> displayCopy = displayedCows;
        //update production and add to display if >=maxProduction
        production[logs[i].cow]+=logs[i].change;
        if(production[logs[i].cow]>=maxProduction){
            maxProduction=production[logs[i].cow];
            if(displayedCows.find(logs[i].cow)==displayedCows.end()){
                displayedCows.insert({logs[i].cow});
            }
        }
        //remove any cows <maxProduction
        for(unordered_set<string>::iterator it=displayedCows.begin();
            it!=displayedCows.end();){
            if(production[*it]<maxProduction){
                it=displayedCows.erase(it);
            }else{
                it++;
            }
        }
        //if the display is empty, add the max producing cows to the display
        if(displayedCows.empty()){
            maxProduction=max(production["Bessie"],max(production["Elsie"],production["Mildred"]));
            for(unordered_map<string,int>::iterator it=production.begin(); it!=production.end(); it++){
                if(it->second==maxProduction){
                    displayedCows.insert({it->first});
                }
            }
        }
        //check if the display has changed. If changed, increment count
        bool counted=false;
        for(unordered_set<string>::iterator it=displayCopy.begin(); it!=displayCopy.end(); it++){
            if(displayedCows.find(*it)==displayedCows.end()){
                count++;
                counted=true;
                break;
            }
        }
        if(counted){continue;}
        for(unordered_set<string>::iterator it=displayedCows.begin(); it!=displayedCows.end(); it++){
            if(displayCopy.find(*it)==displayCopy.end()){
                count++;
                break;
            }
        }
    }
    cout<<count<<"\n";
}
