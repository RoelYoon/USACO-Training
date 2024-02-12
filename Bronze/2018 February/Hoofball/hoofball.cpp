#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct Cow{
    static int idCount;
    int x;
    int id;
    vector<Cow*> passers;
    Cow *pass=nullptr;
    Cow(){
        cin>>x;
        id=idCount++;
    }
    void addPass(Cow *p){
        pass=p;
        pass->passers.push_back(this);
    }
};
int Cow::idCount = 0;
void simulatePassChain(vector<Cow> &cows, bool receivedPass[105], int firstPass){
    Cow* it=&cows[firstPass];
    bool visited[105]{};
    while(!visited[it->id]){
        visited[it->id]=true;
        receivedPass[it->id]=true;
        it=it->pass;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    cin>>n;
    vector<Cow> cows(n);
    sort(cows.begin(),cows.end(),[](const Cow&a, const Cow&b){return a.x<b.x;});
    for(int i = 0; i < n; i++)
        cows[i].addPass(i!=n-1?(i!=0? (abs(cows[i-1].x-cows[i].x)<=abs(cows[i+1].x-cows[i].x) ? &cows[i-1] : &cows[i+1]) : &cows[i+1]) : &cows[i-1]);
    int passes=0;
    bool receivedPass[105]{};
    for(int i = 0; i < n; i++){
        if(cows[i].passers.empty() && !receivedPass[cows[i].id]){
            simulatePassChain(cows,receivedPass,i);
            passes++;
        }
    }
    for(int i = 0; i < n; i++){
        if(!receivedPass[cows[i].id]){
            simulatePassChain(cows,receivedPass,i);
            passes++;
        }
    }
    cout<<passes<<"\n";
}