#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    int n,k; cin>>n>>k;
    string essay="";
    int lineCount = 0;
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        if(lineCount+s.size()<=k){
            essay+=s+" ";
            lineCount+=s.size();
        }else{
            essay.pop_back();
            essay+="\n"+s+" ";
            lineCount=s.size();
        }
    }essay.pop_back();
    cout<<essay<<"\n";
}