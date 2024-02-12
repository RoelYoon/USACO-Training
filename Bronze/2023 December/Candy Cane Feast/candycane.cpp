#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int n,m;
void findMax(vector<ll> &caneHeights,vector<ll> &futureMax,int i){
    if(i == m-1){
        futureMax[i]=caneHeights[i];
        return;
    }
    findMax(caneHeights,futureMax,i+1);
    futureMax[i]=max(futureMax[i+1],caneHeights[i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<ll> cowHeights(n);
    vector<ll> caneHeights(m);
    vector<ll> baseHeights(m,0);
    vector<ll> futureMax(m);
    for(int i = 0; i < n; i++)
        cin>>cowHeights[i];
    for(int i = 0; i < m; i++){
        cin>>caneHeights[i];
    }
    //findMax(caneHeights,futureMax,0);
    //int mEnd = m;
    vector<int> mVals; 
    for(int j = 0; j < m; j++){
        if(caneHeights[j]<=cowHeights[0]){
            //cow is taller
            baseHeights[j]=cowHeights[0];
            cowHeights[0]+=caneHeights[j];
        }else{
            //cow is shorter
            baseHeights[j]=cowHeights[0];
            cowHeights[0]+=cowHeights[0];
        }
        /*
        if(cowHeights[0]>=futureMax[j]){
            mEnd=j;
        }*/
        if(baseHeights[j]<caneHeights[j]){
            mVals.push_back(j);
        }
    }
    for(int i = 1; i < n; i++){
        for(int k = 0; k < mVals.size(); k++){
            int j = mVals[k];
            if(baseHeights[j]>=caneHeights[j]){
                continue;
            }else if(caneHeights[j]<=cowHeights[i]){
                //cow is taller
                ll prev = cowHeights[i];
                cowHeights[i]+=caneHeights[j]-baseHeights[j];
                baseHeights[j]=prev;
            }else if(cowHeights[i]>baseHeights[j]){
                //cow is shorter and taller than base
                ll prev = cowHeights[i];
                cowHeights[i]+=cowHeights[i]-baseHeights[j];
                baseHeights[j]=prev;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<cowHeights[i]<<"\n";
    }
}