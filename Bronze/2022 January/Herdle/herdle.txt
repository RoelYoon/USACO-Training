/*
ID: roelyoon
TASK: herdle
LANG: C++                 
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int green=0, yel=0;
    string ans="", guess="";
    for(int i = 0; i < 6; i++){
        string temp;
        cin>>temp;
        if(i<3){ans+=temp;}else{guess+=temp;}
    }
    vector<int> lookup(27);
    for(char c : ans){
        lookup[c-64]++;
    }
    for(int i = 0; i < 9; i++){
        if(guess[i]==ans[i]){
            lookup[guess[i]-64]--;
            if(lookup[guess[i]-64]<0){
                yel--;
            }
            green++;
        }
        else if(lookup[guess[i]-64]>0){
            lookup[guess[i]-64]--;
            yel++;
        }
    }
    cout<<green<<"\n"<<yel<<"\n";
}