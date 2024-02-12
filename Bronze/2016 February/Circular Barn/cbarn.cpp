#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    cin>>n;
    int r[1005];
    for(int i = 0; i < n; i++){
        cin>>r[i];
    }
    int minScore = 1000000000;
    for(int i = 0; i < n; i++){
        int score = 0; 
        for(int j = 0; j < n; j++){
            score+=(i<=j?abs(j-i):n-abs(j-i))*r[j];
        }
        minScore=min(score,minScore);
    }
    cout<<minScore<<"\n";
}
