/*
ID: roelyoon
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
struct Farmer{
    int price; 
    int supply; 
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("milk.in","r",stdin);
    //freopen("milk.out","w",stdout);
    int n, m; cin>>n>>m; 
    vector<Farmer> farmers(m);
    for(int i = 0; i < m; i++)
        cin>>farmers[i].price>>farmers[i].supply;
    sort(farmers.begin(),farmers.end(),[](Farmer &a, Farmer &b){return a.price<b.price;});
    int price=0;
    for(int i = 0; i < m; i++){
        if(farmers[i].supply<n){
            n-=farmers[i].supply;
            price+=farmers[i].supply * farmers[i].price; 
            if(n==0){break;}
        }else{
            while(n>0){
                n--; 
                price+=farmers[i].price;
            }
            break;
        }
    }
    cout<<price<<"\n";
}