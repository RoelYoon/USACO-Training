/*
ID: roelyoon
TASK: ariprog
LANG: C++                 
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n,m; 
int maxA, maxB; 
unordered_set<int> bisquares; 
vector<pair<int,int>> ans; 
/*
void findSequence(int a, int b, int i){
    if(bisquares.find(a+b*i)==bisquares.end()){
        return; 
    }
    if(i==n-1){
        ans.push_back(make_pair(a,b));
    }findSequence(a,b,i+1); 
}*/
bool findSequence(int a, int b, int i){
    if(bisquares.find(a+b*i)==bisquares.end()){
        return false; 
    }
    if(i==n-1){
        //ans.push_back(make_pair(a,b));
        return true;
    }return findSequence(a,b,i+1); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    cin>>n>>m;
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            bisquares.insert({i*i+j*j});
    maxA = m*m+n*n;
    int a = 0; 
    int maxB = ((m*m))/n;
    unordered_set<int>::iterator it = bisquares.begin(); 
    a=*it;
    do{
        for(int b = 1; b < maxB; b++){
            /*
            if(bisquares.find(a+b*(n-1))==bisquares.end()){continue;}
            findSequence(a,b,0);
            */
            if(bisquares.find(a+b)!=bisquares.end()
            && bisquares.find(a+b*2)!=bisquares.end() 
            && bisquares.find(a+b*(n-1))!=bisquares.end() 
            && bisquares.find(a+b*(n/2))!=bisquares.end()
            && bisquares.find(a+b*(n/2+1))!=bisquares.end()
            && bisquares.find(a+b*(n/2-1))!=bisquares.end()
            && bisquares.find(a+b*(n/3))!=bisquares.end()
            && bisquares.find(a+b*(n/3-1))!=bisquares.end()
            && bisquares.find(a+b*(n/3+1))!=bisquares.end()
            && bisquares.find(a+b*(n/4))!=bisquares.end()
            && findSequence(a,b,0)){
                ans.push_back(make_pair(a,b));
            }
        }
        it++; if(it==bisquares.end()){break;}
        a = *it; 
        maxB=(2*(m*m)-a)/n+6;
        //cout<<maxB<<endl;
    }while(maxB>0);
    if(ans.empty()){cout<<"NONE\n";}
    else{
        sort(ans.begin(),ans.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.first<b.first;});
        stable_sort(ans.begin(),ans.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.second<b.second;});
        for(int i = 0; i < ans.size(); i++)
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}
