#include <iostream>
using namespace std;
struct Bucket{
    int capacity;
    int filled; 
    Bucket(){cin>>capacity>>filled;}
};
void pour(Bucket &passer, Bucket &receiver){
    int receiverSpace = receiver.capacity-receiver.filled;
    if(passer.filled <= receiverSpace){
        receiver.filled+=passer.filled;
        passer.filled=0;
    }else{
        passer.filled-=receiverSpace;
        receiver.filled=receiver.capacity;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    Bucket buckets[3];
    for(int i = 0; i < 100; i++)
        pour(buckets[i%3],buckets[(i+1)%3]);
    for(int i = 0; i < 3; i++)
        cout<<buckets[i].filled<<"\n";
}