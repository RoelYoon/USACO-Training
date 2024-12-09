#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
unordered_map<string,int> id{
    {"Beatrice",0},
    {"Belinda",1},
    {"Bella",2},
    {"Bessie",3},
    {"Betsy",4},
    {"Blue",5},
    {"Buttercup",6},
    {"Sue",7}
};
vector<string> names{
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"
};
struct Constraint{
    int c1,c2;
    Constraint(){}
    Constraint(int c1, int c2):c1(c1),c2(c2){}
};
vector<Constraint> constraints;
bool valid(vector<int> &order){
    for(int i = 0; i < constraints.size(); ++i){
        for(int j = 0; j < order.size(); ++j){
            if(order[j]==constraints[i].c1){
                if(!(((j+1<8)&&(order[j+1]==constraints[i].c2)) || 
                ((j-1>=0)&&(order[j-1]==constraints[i].c2)))){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        string c1,c2; cin>>c1;
        for(int i = 0; i < 4; ++i){string t;cin>>t;}
        cin>>c2;
        constraints.emplace_back(id[c1],id[c2]);
    }
    vector<int> order(8);
    vector<string> valids;
    bool s[8]{};
    for(int i = 0; i < 8; ++i){
        s[i]=1;
        order[i]=0;
        for(int j = 0; j < 8; ++j){
            if(s[j]) continue;
            order[j]=1;
            s[j]=1;
            for(int k = 0; k < 8; ++k){
                if(s[k]) continue;
                order[k]=2;
                s[k]=1;
                for(int i2 = 0; i2 < 8; ++i2){
                    if(s[i2]) continue;
                    order[i2]=3;
                    s[i2]=1;
                    for(int j2 = 0; j2 < 8; ++j2){
                        if(s[j2]) continue;
                        order[j2]=4;
                        s[j2]=1;
                        for(int k2 = 0; k2 < 8; ++k2){
                            if(s[k2]) continue;
                            order[k2]=5;
                            s[k2]=1;
                            for(int i3 = 0; i3 < 8; ++i3){
                                if(s[i3]) continue;
                                order[i3]=6;
                                s[i3]=1;
                                for(int j3 = 0; j3 < 8; ++j3){
                                    if(s[j3]) continue;
                                    order[j3]=7;
                                    s[j3]=1;
                                    if(valid(order)){
                                        string validO = "";
                                        for(int i = 0; i < 8; ++i){
                                            validO+=names[order[i]]+"\n";
                                        }
                                        valids.push_back(validO);
                                    }
                                    s[j3]=0;
                                }
                                s[i3]=0;
                            }
                            s[k2]=0;
                        }
                        s[j2]=0;
                    }
                    s[i2]=0;
                }
                s[k]=0;
            }
            s[j]=0;
        }
        s[i]=0;
    }
    sort(valids.begin(),valids.end());
    cout<<valids[0];
}