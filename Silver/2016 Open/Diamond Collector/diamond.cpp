#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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
    unordered_set<int> included;
    for(int diamond = 0; diamond < n; diamond++){
        int score = 0;
        int other = diamond;
        unordered_set<int> tempIncluded;
        while(other<n && abs(diamonds[other]-diamonds[diamond])<=k){
            score++;
            other++;
            tempIncluded.insert({other});
        }
        if(score>maxScore){
            maxScore = score;
            included=tempIncluded;
        }
    }
    int maxScore2 = 0;
    for(int diamond = 0; diamond < n; diamond++){
        if(included.find(diamond)!=included.end()){continue;}
        int score = 0;
        int other = diamond;
        while(other<n && abs(diamonds[other]-diamonds[diamond])<=k){
            if(included.find(other)!=included.end()){other++;continue;}
            score++;
            other++;
        }
        if(score>maxScore2){
            maxScore2 = score;
        }
    }
    cout<<maxScore+maxScore2<<"\n";
}
