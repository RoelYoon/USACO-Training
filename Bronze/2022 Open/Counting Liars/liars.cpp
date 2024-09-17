#include <iostream>
#include <vector>
using namespace std;
struct Info{
    bool GE;
    int p;
    Info(){}
    Info(bool g , int p):GE(g),p(p){}
};
int main(){
   int n; cin>>n;
   vector<Info> infos(n);
   for(int i = 0; i < n; ++i){
        char g; cin>>g>>infos[i].p;
        infos[i].GE=g=='G';
   }
   int minLiar = 1000000000;
   for(int i = 0; i < n; ++i){
       int cnt = 0; 
       for(int j = 0; j < n; ++j){
           if(infos[j].GE){
               cnt+=infos[i].p<infos[j].p;
           }else{
               cnt+=infos[i].p>infos[j].p;
           }
       }
       minLiar = min(minLiar,cnt);
   }
   cout<<minLiar<<"\n";
}
