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
#include <memory> 
using namespace std;
int n, cyclicLinkCount=0;
struct Portal{
    string id; 
    int x;
    int y; 
    shared_ptr<Portal> next = NULL;
    shared_ptr<Portal> pair = NULL;
};
bool floydCycleDetection(shared_ptr<Portal> &head){
    shared_ptr<Portal> slowPointer = head;
    shared_ptr<Portal> fastPointer = head;
    bool exitedPortal=false; 
    while(slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = exitedPortal ? slowPointer->pair : slowPointer->next;
        exitedPortal=!exitedPortal; 
        fastPointer = fastPointer->next->pair;
        if (slowPointer == fastPointer)
            return true;
    }
    return false;
}
void ID_Permutation(unordered_set<string> &generated,string &id,bitset<12> set,string permutation){
    if(set.count()==n/2){generated.insert({permutation}); return;}
    int pos = 0;
    for(int i = 0; i < id.size();i++){
        string pairID="";
        while(id[i]!='.'){pairID.push_back(id[i]); i++;}
        if(!set.test(pos)){
            set[pos]=1;
            ID_Permutation(generated,id,set,permutation+pairID+".");
            set[pos]=0;
        }
        pos++;
    }
}
void generateLinks(vector<shared_ptr<Portal>> &portals,unordered_set<string> &generated,string id,int depth){
    if(depth==n/2){
        if(generated.find(id)==generated.end()){
            bool isCyclic = false; 
            for(int i = 0; i < n; i++){
                if(floydCycleDetection(portals[i])){
                    isCyclic=true;
                    break;
                }
            }
            if(isCyclic){cyclicLinkCount++;}
            ID_Permutation(generated,id,bitset<12>(),"");
        }
        return;
    }
    for(shared_ptr<Portal> p1 : portals){
        if(p1->pair==NULL){
            for(shared_ptr<Portal> p2 : portals){
                if(p2->pair==NULL && p2!=p1){
                    p1->pair=p2;
                    p2->pair=p1; 
                    generateLinks(portals,generated,id+(p1->id<p2->id?p1->id:p2->id)+"-"+(p2->id>p1->id?p2->id:p1->id)+".",depth+1);
                    p1->pair=NULL;
                    p2->pair=NULL;
                }
            }
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
        p->id=to_string(i);
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
    unordered_set<string> generated; 
    generateLinks(portals,generated,"",0);
    cout<<cyclicLinkCount<<"\n"; 
}