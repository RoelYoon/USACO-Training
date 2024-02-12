#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    cin>>n>>k;
    vector<int> diamonds(n);
    for(int i = 0; i < n; i++){
        cin>>diamonds[i];
    }
    sort(diamonds.begin(),diamonds.end());
    int maxScore = 0;
    for(int diamond = 0; diamond < n; diamond++){
        int score = 0;
        int other = diamond;
        while(other<n && abs(diamonds[other]-diamonds[diamond])<=k){
            score++;
            other++;
        }
        maxScore = max(score,maxScore);
    }
    cout<<maxScore<<"\n";
}
