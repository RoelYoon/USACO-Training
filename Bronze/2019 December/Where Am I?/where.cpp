#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int n;
string s;
bool works(int k){
    unordered_set<string> set; 
    for(int i = 0; i <= n-k; i++){
        string s2 = s.substr(i,k);
        if(set.find(s2)!=set.end()){return false;}
        set.insert({s2});
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    cin>>n>>s;
    int low = 1, high = n-1;
    high++;
    while(low<high){
        int k = (low+high-1)/2;
        if(works(k)){
            high=k;
        }else{
            low=k+1;
        }
    }
    cout<<low<<"\n";
}
