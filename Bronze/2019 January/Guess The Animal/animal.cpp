#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
struct Animal{
    string name;
    unordered_set<string> characters;
    Animal(){
        int c;
        cin>>name>>c;
        for(int i = 0; i < c; i++){
            string temp; cin>>temp;
            characters.insert({temp});
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int n; cin>>n;
    vector<Animal> animals(n);
    int maxMatch = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int match = 0; 
            for(unordered_set<string>::iterator it=animals[i].characters.begin(); it!=animals[i].characters.end(); it++)
                if(animals[j].characters.find(*it)!=animals[j].characters.end())
                    match++;
            maxMatch = max(maxMatch,match);
        }
    }
    cout<<maxMatch+1<<"\n";
}