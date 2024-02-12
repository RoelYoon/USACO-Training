#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#define ll long long
using namespace std;
struct Point{
    ll pos; ll taste;
    Point(int p):pos(p*10){}
    virtual bool isCow(){};
    bool operator==(const Point &other){
        return pos==other.pos;
    }
};
struct Grass : Point{
    //ll taste;
    Grass(int p, int t):Point(p){taste=t;}
    bool isCow(){return false;}
};
struct NhojCow : Point{
    NhojCow(int p):Point(p){}
    bool isCow(){return true;}
};
struct PatchRange{
    ll leftBound;
    ll rightBound;
    Grass patch;
    PatchRange(ll l, ll r, Grass p):leftBound(l),rightBound(r),patch(p){}
    struct PatchPointerHash{
        bool operator()(const PatchRange* p){
            return hash<ll>{}(p->leftBound)^hash<ll>{}(p->rightBound);
        }
    };
    bool operator==(const PatchRange& other){
        return leftBound==other.leftBound && rightBound==other.rightBound;
    }
};
template<class minCompare, class maxCompare>
struct Group{
    vector<PatchRange> storage;
    priority_queue<PatchRange*,vector<PatchRange*>,minCompare> minPQ; 
    priority_queue<PatchRange*,vector<PatchRange*>,maxCompare> maxPQ;
    unordered_set<PatchRange*,PatchRange::PatchPointerHash> set;
    ll totalTaste;
    Group(const minCompare& minCmp, const maxCompare& maxCmp):minPQ(priority_queue<PatchRange*,vector<PatchRange*>,minCompare>(minCmp)),maxPQ(priority_queue<PatchRange*,vector<PatchRange*>,maxCompare>(maxCmp)),totalTaste(0){}
    void push(PatchRange p){
        totalTaste+=p.patch.taste;
        storage.push_back(p);
        PatchRange* pp = &storage.back();
        set.insert({pp});
        minPQ.push(pp);
        maxPQ.push(pp);
    }
    void pop(PatchRange* p){
        totalTaste-=p->patch.taste;
        set.erase({p});
        minCleanTop();
        maxCleanTop();
    }
    void clear(){
        totalTaste=0;
        set.clear();
        minPQ.clear();
        maxPQ.clear();
    }
    void minCleanTop(){
        while(set.find(*minPQ.top())==set.end()){minPQ.pop();}
    }
    void maxCleanTop(){
        while(set.find(*maxPQ.top())==set.end()){maxPQ.pop();}
    }
    void minPop(){
        minCleanTop();
        minPQ.pop();
    }
    PatchRange* minTop(){
        minCleanTop()
        return minPQ.top();
    }
    void maxPop(){
        maxCleanTop();
        maxPQ.pop();
    }
    PatchRange* maxTop(){
        maxCleanTop();
        return maxPQ.top();
    }
};
int k,m,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>m>>n;
    vector<Point> points;
    for(int i = 0; i < k; i++){
        ll p,t;
        cin>>p>>t;
        points.push_back(Grass(p,t));
    }
    for(int i = 0; i < m; i++){
        ll p;
        cin>>p;
        points.push_back(NhojCow(p));
    }
    sort(points.begin(),points.end(),[](const Point &a, const Point &b){return a.pos<b.pos;});
    auto minCMP = [](const PatchRange *a, const PatchRange *b){return a->rightBound>b->rightBound;};
    auto maxCMP = [](const PatchRange *a, const PatchRange *b){return a->rightBound<b->rightBound;}; 
    Group<decltype(minCMP),decltype(maxCMP)> group(minCMP,maxCMP);
    auto groupCMP = [](const Group<decltype(minCMP),decltype(maxCMP)> *a, const Group<decltype(minCMP),decltype(maxCMP)> *b){return a->totalTaste>b->totalTaste;};
    vector<Group<decltype(minCMP),decltype(maxCMP)>> storage;
    priority_queue<Group<decltype(minCMP),decltype(maxCMP)>*,vector<Group<decltype(minCMP),decltype(maxCMP)>*>,decltype(groupCMP)> groups(groupCMP);
    ll lastCut = -1;
    for(int i = 0; i < k+m; i++){
        if(points[i].isCow() || i==(k+m)-1){
            lastCut = points[i].pos + 5;
            while(group.maxPQ.top()->rightBound>lastCut){
                PatchRange *p = *group.set.find(group.maxPQ.top());
                p->rightBound=lastCut;
                group.maxPQ.pop();
                group.maxPQ.push(p);
            }
            storage.push_back(group);
            groups.push(&storage.back());
            group.clear();
        }else{
            while(group.minTop()->rightBound < points[i].pos){
                storage.push_back(group);
                groups.push(&storage.back());
                group.pop(group.minTop());
            }
            group.push(PatchRange(lastCut,points[i].pos+(abs(points[i].pos-lastCut)),Grass(points[i].pos,points[i].taste)));
        }
    }
    ll maxTaste=0;
    ll leftBound=2000000005, rightBound=-1;
    while(n--){
        /*
        bool skip=false;
        for(unordered_set<PatchRange*,PatchRange::PatchPointerHash>::iterator setIt = groups.top().set.begin(); setIt!=groups.top().set.end(); setIt++){
            if(!((*setIt)->leftBound>rightBound || (*setIt)->rightBound<leftBound)){
                groups.pop();
                skip=true;
                break;
            }
        }*/
        //leftBound=min(leftBound,groups.top().maxTop()->leftBound);
        //rightBound=max(rightBound,groups.top().maxTop()->rightBound);
        leftBound = min(leftBound,groups.top()->maxTop()->leftBound);
        rightBound = min(rightBound,groups.top()->maxTop()->rightBound);
        maxTaste+=groups.top()->totalTaste;
    }
    cout<<maxTaste<<"\n";
}