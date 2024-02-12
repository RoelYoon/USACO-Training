#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Cow{
    int order;
    int id;
    Cow* pair = nullptr;
    Cow* pair2 = nullptr;
    Cow(int id):id(id),order(id){};
};
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("lineup.in","r",stdin);
    //freopen("lineup.out","w",stdout);
    string cowNames[8]{
        "Beatrice",
        "Belinda",
        "Bella",
        "Bessie",
        "Betsy",
        "Blue",
        "Buttercup",
        "Sue"
    };
    unordered_map<string,int> cowID_Map;
    cowID_Map = {
        {"Beatrice",0},
        {"Belinda",1},
        {"Bella",2},
        {"Bessie",3},
        {"Betsy",4},
        {"Blue",5},
        {"Buttercup",6},
        {"Sue",7},
    };
    cin>>n;
    vector<Cow> cows;
    for(int i = 0; i < 8; i++){
        cows.push_back(Cow(i));
    }
    for(int i = 0; i < n; i++){
        string s1,s2; cin>>s1;
        for(int j = 0; j < 4; j++){
            cin>>s2;
        }
        cin>>s2;
        if(cows[cowID_Map[s1]].pair==nullptr){
            cows[cowID_Map[s1]].pair = &cows[cowID_Map[s2]];
        }else{
            cows[cowID_Map[s1]].pair2 = &cows[cowID_Map[s2]];
        }
        if(cows[cowID_Map[s2]].pair==nullptr){
            cows[cowID_Map[s2]].pair = &cows[cowID_Map[s1]];
        }else{
           cows[cowID_Map[s2]].pair2 = &cows[cowID_Map[s1]];
        }
    }
    while(1){
        int notMatched = -1;
        for(int i = 7; i >= 0; i--){
            if((!(i>0?cows[i].pair!=nullptr?cows[i-1].id==cows[i].pair->id:true:true) || (i<n-1?cows[i].pair!=nullptr?cows[i+1].id==cows[i].pair->id:true:true))){
                notMatched=i;
                Cow
            }
        }
        if(notMatched==-1){
            break;
        }
    }
    for(int i = 0; i < 8; i++){
        cout<<cowNames[cows[i].id]<<"\n";
    }
    /*
    for(int i = 0; i < 8; i++){
        cout<<cowNames[cows[i].id]<<": "<<(cows[i].pair!=nullptr?cowNames[cows[i].pair->id]:"")<<"\n";
    }*/
}