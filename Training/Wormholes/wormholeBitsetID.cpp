/*
ID: roelyoon
TASK: wormhole
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set> 
#include <bitset>
#include <utility>
#include <memory> 
using namespace std;
int n, cyclicLinkCount=0; int testCount = 0;
struct Portal{
    int id; 
    int x;
    int y; 
    shared_ptr<Portal> next = NULL;
    shared_ptr<Portal> pair = NULL;
    struct Hash{
        size_t operator()(const shared_ptr<Portal>& portal) const{
            return hash<int>()(portal->id);
        }
    };
};
bool floydCycleDetection(shared_ptr<Portal> &head){
    shared_ptr<Portal> slowPointer = head->next;
    shared_ptr<Portal> fastPointer = head;
    bool exitedPortal=false; 
    while(slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = exitedPortal ? slowPointer->next : slowPointer->pair;
        exitedPortal=!exitedPortal; 
        fastPointer = fastPointer->next->pair;
        if (slowPointer == fastPointer)
            return true;
    }
    return false;
}
void generateLinks(vector<shared_ptr<Portal>> &portals,unordered_set<bitset<145>> &generated,unordered_set<int> &cyclicPairs, unordered_map<int,pair<shared_ptr<Portal>,shared_ptr<Portal>>> &bitmap, unordered_set<shared_ptr<Portal>,Portal::Hash> set, bitset<145> id){
    if(id.count()==n/2){
        if(generated.find(id)==generated.end()){
            generated.insert({id});
            for(int i = 0; i < bitmap.size(); i++){
                if(id.test(i) && cyclicPairs.find(i)!=cyclicPairs.end()){
                    cyclicLinkCount++;
                    testCount++;
                    return;
                }
            }
            for(shared_ptr<Portal> p : portals){
                if(floydCycleDetection(p)){
                    cyclicLinkCount++;
                    return;
                }
            }
        }
        return;
    }
    for(int i = 0; i < bitmap.size(); i++){
        pair<shared_ptr<Portal>,shared_ptr<Portal>> portalPair = bitmap.find(i)->second;
        if(set.find(portalPair.first)==set.end() && set.find(portalPair.second)==set.end()){
            set.insert({portalPair.first,portalPair.second});
            id[i]=1;
            portalPair.first->pair = portalPair.second;
            portalPair.second->pair = portalPair.first;
            generateLinks(portals,generated,cyclicPairs,bitmap,set,id);
            set.erase(portalPair.first); set.erase(portalPair.second);
            id[i]=0;
            portalPair.first->pair = NULL;
            portalPair.second->pair = NULL;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("wormhole.in","r",stdin);
    //freopen("wormhole.out","w",stdout);
    cin>>n;
    unordered_map<int, vector<shared_ptr<Portal>>> portalMap; 
    vector<shared_ptr<Portal>> portals;
    for(int i = 0; i < n; i++){
        shared_ptr<Portal> p = make_shared<Portal>();
        cin>>p->x>>p->y;
        p->id=i;
        unordered_map<int,vector<shared_ptr<Portal>>>::iterator it = portalMap.find(p->y);
        if(it==portalMap.end()){portalMap.insert({p->y,vector<shared_ptr<Portal>>(1,p)});}
        else{(it->second).push_back(p);}
        portals.push_back(p);
    }
    for(unordered_map<int,vector<shared_ptr<Portal>>>::iterator it = portalMap.begin(); it!=portalMap.end(); it++){
        if(it->second.size()==1){continue;}
        sort(it->second.begin(), it->second.end(), [](shared_ptr<Portal> &a, shared_ptr<Portal> &b){return a->x<b->x;});
        for(int i = 0; i<it->second.size()-1; i++)
            it->second[i]->next = it->second[i+1];
    }
    unordered_set<bitset<145>> generated; 
    unordered_map<int,pair<shared_ptr<Portal>,shared_ptr<Portal>>> bitmap; 
    unordered_set<int> cyclicPairs;
    unordered_set<int> paired; 
    for(shared_ptr<Portal> p1 : portals){
        if(p1->pair==NULL){
            paired.insert({p1->id});
            for(shared_ptr<Portal> p2 : portals){
                if(p2->pair==NULL && paired.find(p2->id)==paired.end()){
                    if(p1->next == p2 || p2->next == p1)
                        cyclicPairs.insert({(int)bitmap.size()});
                    bitmap.insert({bitmap.size(),make_pair(p1,p2)});
                }
            }
        }
    }
    generateLinks(portals,generated,cyclicPairs,bitmap,unordered_set<shared_ptr<Portal>,Portal::Hash>(),bitset<145>());
    cout<<testCount<<"\n";
    cout<<cyclicLinkCount<<"\n"; 
}
/*
12 
636437309 704270751 
695056713 700147825 
636437309 356396548 
921201220 589666013 
430411607 671693685 
324259336 671693685 
723442153 589666013 
528904109 419799944 
921201220 356396548 
723442153 856537355 
691516566 726853849 
941903572 634527403
Time Complexity: O(n^2*(n-1)!!) woah!
2535 2835
Optimization with combinatorics: ((n*((n-1)/2 + 2))! / ((n-1)!*(n*(n-1)/2)-3n+3))
*/