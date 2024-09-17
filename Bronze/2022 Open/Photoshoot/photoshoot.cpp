#include <iostream>
#include <bitset>
#define MAX 100005
using namespace std;
int main(){
    int n; cin>>n;
    string s; cin>>s;
    bitset<MAX> ps(0);
    int j = 0;
    for(int i = 0; i < n; i+=2){
        string ss = s.substr(i,2);
        if(ss == "GH"){
            j++;
        }else if(ss=="HG"){
            ps[j++]=1;
        }
    }
    int cnt = 0;
    for(int i = j-1; i >= 0; --i){
        if(!ps[i]){
            for(int k = 0; k <=i; ++k){
                ps[k].flip();
            }
            ++cnt;
        }
    }
   cout<<cnt<<"\n";
}