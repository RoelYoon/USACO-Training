#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    string s; cin>>s;
    string map="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool pairFound[26][26]{{}};
    int pairCount = 0;
    for(int i = 0; i < 26; i++){
        char cow = map[i];
        int point1 = s.find(cow);
        int point2 = (s.substr(point1+1,52-(point1)).find(cow))+point1+1;
        bool isPair[26]{};
        //clockwise traversal
        for(int j = point1+1; j < point2; j++){
            isPair[s[j]-65]=!isPair[s[j]-65];
        }
        for(int j = 0; j < 26; j++){
            if(isPair[j] && !pairFound[i][j]){
                pairFound[i][j]=true;
                pairFound[j][i]=true;
                pairCount++;
            }
            isPair[j]=0;
        }
        //counter-clockwise traversal
        for(int j = point2!=51?point2+1:0; j != point1; j=(j+1)%52){
            isPair[s[j]-65]=!isPair[s[j]-65];
        }
        for(int j = 0; j < 26; j++){
            if(isPair[j] && !pairFound[i][j]){
                pairFound[i][j]=true;
                pairFound[j][i]=true;
                pairCount++;
            }
        }
    }
    cout<<pairCount<<"\n";
}
