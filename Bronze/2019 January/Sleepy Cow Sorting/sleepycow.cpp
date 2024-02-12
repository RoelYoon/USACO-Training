#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
int n;
int sortedIndex(list<int> &line){
    list<int>::reverse_iterator it = line.rbegin();
    int i = n; 
    int last = *it; 
    while(it!=line.rend()){
        if(*it>last){
            return i;
        }
        last=*it;
        i--;
        it++;
    }
    return 0; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    cin>>n;
    list<int> line; 
    for(int i = 0; i < n; i++){
        int temp; cin>>temp; 
        line.insert(line.end(),temp);
    }
    int count = 0;
    while(1){
        int lastSortedPos = sortedIndex(line);
        list<int>::iterator it = line.begin();
        advance(it,lastSortedPos);
        if(*(line.begin())==1){
            if(lastSortedPos==0){break;}
            line.insert(it,1);
            line.pop_front(); 
        }else{
            while(*it<*(line.begin()) && it!=line.end()){
                it++;
            }
            line.insert(it,*(line.begin()));
            line.pop_front();
        }
        count++;
    }
    cout<<count<<"\n";
}