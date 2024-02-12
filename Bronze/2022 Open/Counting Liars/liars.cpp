#include <iostream>
using namespace std;
int n;
bool greaterMap[1005];
long long placeMap[1005];
bool agrees(int truthID,int cow2ID){
    return greaterMap[truthID]==greaterMap[cow2ID] || placeMap[truthID]==placeMap[cow2ID] ||
    (placeMap[truthID]>placeMap[cow2ID] && greaterMap[cow2ID] && !greaterMap[truthID]) ||
    (placeMap[truthID]<placeMap[cow2ID] && !greaterMap[cow2ID] && greaterMap[truthID]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int maxTruthValue=0;
    for(int i = 0; i < n; i++){
        char temp;
        cin>>temp>>placeMap[i];
        greaterMap[i]=temp=='G'?1:0;
    }
    for(int cow1 = 0; cow1 < n; cow1++){
        int truthValue = 0;
        for(int cow2 = 0; cow2 < n; cow2++){
            if(agrees(cow1,cow2)){
                truthValue++;
            }
        }
        maxTruthValue = maxTruthValue>truthValue?maxTruthValue:truthValue;
    }
    cout<<n-maxTruthValue<<"\n";
}
