#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int limits[25]; 
int n;
int fit(int height){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(limits[i] >= height)
            count++;
    return count; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> heights(n); 
    for(int i = 0; i < n; i++)
        cin>>heights[i];
    for(int i = 0; i < n; i++)
        cin>>limits[i]; 
    sort(heights.begin(),heights.end());
    ll arrangements = 1; 
    for(int i = n-1; i>=0; i--)
        arrangements*=(fit(heights[i])-(n-1-i)); 
    cout<<arrangements<<"\n";
}
