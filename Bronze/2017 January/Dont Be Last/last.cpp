#include <iostream>
#include <unordered_map>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    unordered_map<string, int> mapping = {{"Bessie",0},
    {"Elsie",0},
    {"Daisy",0},
    {"Gertie",0},
    {"Annabelle",0},
    {"Maggie",0},
    {"Henrietta",0}};
    cin>>n;
    for(int i = 0; i < n; i++){
        string name; int milk;
        cin>>name>>milk;
        mapping[name]+=milk;
    }
    int minMilk = 1000000000;
    string minCow;
    for(unordered_map<string,int>::iterator it = mapping.begin();
    it!=mapping.end(); it++){
        if(it->second<minMilk){
            minMilk=it->second;
            minCow=it->first;
        }
    }
    int minMilk2 = 1000000000; bool ansSet=false;
    string ans;
    for(unordered_map<string,int>::iterator it = mapping.begin();
    it!=mapping.end(); it++){
        if(it->second<minMilk2 && it->second!=minMilk){
            minMilk2=it->second;
            ans=it->first;
            ansSet=true;
        }
    }
    if(!ansSet){
        cout<<"Tie\n";
        return 0;
    }
    for(unordered_map<string,int>::iterator it = mapping.begin();
    it!=mapping.end(); it++){
        if(it->second==minMilk2 && it->first!=ans){
            cout<<"Tie\n";
            return 0;
        }
    }
    cout<<ans<<"\n";
}