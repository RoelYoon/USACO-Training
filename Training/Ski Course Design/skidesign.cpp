/*
ID: roelyoon
TASK: skidesign
LANG: C++                 
*/
#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n; cin>>n; 
    vector<int> hills(n); 
    for(int i = 0; i < n; i++)
        cin>>hills[i];
    int minCost = INT_MAX; 
    for(int k = 0; k <= 100; k++){
        int cost = 0;
        vector<int> changes(n,0);
        int leftCost=0, rightCost=0;
        for(int i = 0; i < n; i++){
            int dif = abs(hills[i]-k);
            if(dif>8){
                changes[i]=dif-8;
                if(i<k){
                    leftCost+=pow(changes[i],2);
                }else{
                    rightCost+=pow(changes[i],2);
                }
            }
        }
        if(leftCost!=rightCost){
        for(int i = 0; i < n; i++){
            if(hills[i]<k && changes[i]!=0 && leftCost>rightCost){
                changes[i]--;
            }else if(hills[i]>k && changes[i]!=0 && rightCost>leftCost){
                changes[i]--;
            }
            cost+=pow(changes[i],2);
        }}else{
            int p1=0,p2=0;
        for(int i = 0; i < n; i++){
            if(hills[i]<k && changes[i]!=0){
                p1+=pow(changes[i]-1,2);
            }else if(hills[i]>k && changes[i]!=0){
                p2+=pow(changes[i]-1,2);
            }
        }
        cost=min(p1,p2);
        }
        minCost=min(minCost,cost);
    }
    cout<<minCost<<"\n";
}