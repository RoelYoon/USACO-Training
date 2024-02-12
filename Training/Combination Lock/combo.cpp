/*
ID: roelyoon
TASK: combo
LANG: C++                 
*/
#include <iostream>
using namespace std;
int n; 
struct Dial{
    int val=1;
    int leftBound=n-1;
    int rightBound=3;
    void setVal(int v){
        val=v;
        leftBound=(v-2 < 1 ? n+(v-2) : v-2);
        rightBound=(v+2 > n ? v+2-n : v+2);
    }
    Dial(){}
    Dial(int v){setVal(v);}
};
struct Combination{
    Dial first;
    Dial second;
    Dial third;
    bool addOne(){
        if(third.val==n){
            third.setVal(1);
            if(second.val==n){
                second.setVal(1);
                if(first.val==n){
                    return false;
                }else{
                    first.setVal(first.val+1);
                }
            }else{
                second.setVal(second.val+1);
            }
        }else{
            third.setVal(third.val+1);
        }
        return true;
    }
    Combination(){}
};
bool isClose(Dial &a, Dial &b){
    int i = a.leftBound-1;
    while(i != a.rightBound){
        i = (i+1 > n ? i+1-n : i+1);
        if(i==b.val){
            return true;
        }
    }
    i = a.leftBound-1;
    while(i != a.val){
        i = (i+1 > n ? i+1-n : i+1);
        if(i==b.val){
            return true;
        }
    }
    if(n==4) //extreme edge cases
        if(a.val==2 || b.val==2 || a.val==4 || b.val==4)
            return true;
    return false; 
}
bool isValid(Combination &trial, Combination &john, Combination &master){
    return isClose(trial.first,john.first) && isClose(trial.second,john.second) && isClose(trial.third,john.third) || isClose(trial.first,master.first) && isClose(trial.second,master.second) && isClose(trial.third,master.third);
}
void countComb(Combination comb, Combination &john, Combination &master, int &count, Combination &save, int &depth, bool &maxed){
    if(depth==10000){
        maxed=true;
        save=comb;
        return;
    }
    if(isValid(comb,john,master)){
        count++;
    }
    if(comb.addOne()){
        depth++;
        countComb(comb,john,master,count,save,depth,maxed);
    }
    if(!maxed){depth=-1;} 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("combo.in","r",stdin);
    //freopen("combo.out","w",stdout);
    Combination john;
    Combination master;
    cin>>n>>john.first.val>>john.second.val>>john.third.val>>master.first.val>>master.second.val>>master.third.val;
    john.first.setVal(john.first.val); john.second.setVal(john.second.val); john.third.setVal(john.third.val);
    master.first.setVal(master.first.val); master.second.setVal(master.second.val); master.third.setVal(master.third.val);
    int count = 0; 
    int depth = 0;
    bool maxed = false;
    Combination save; 
    while(depth!=-1){
        depth=0;
        countComb(save,john,master,count,save,depth,maxed);
        maxed=false;
    }
    cout<<count<<"\n";
    return 0;
}