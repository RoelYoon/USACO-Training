#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
using namespace std;
#define MAX 100005
struct SegmentTreeNode{
    int leftBound;
    int rightBound; 
    unordered_set<int> milkSet; //contains all the types of milk in range [leftBoundd,rightBound]
    SegmentTreeNode(){}
    //initialization for leaf nodes
    void initialize(int l, int r, int milk){
        setBounds(l,r); 
        milkSet.insert({milk}); 
    }
    //initializes internal nodes by merging the milksets of children
    void initialize(int l, int r, unordered_set<int> &a, unordered_set<int> &b){
        setBounds(l,r); 
        set_union(begin(a),end(a),
        begin(b), end(b),        
        inserter(milkSet,begin(milkSet)));
    }
    void setBounds(int l, int r){
        leftBound=l;
        rightBound=r; 
    }
    bool containsMilk(int milk){
        return milkSet.find(milk)!=milkSet.end(); 
    }
};
struct SegmentTree{
    #define PARENT(i) ((i-1)/2)
    #define LEFTCHILD(i) ((2*i+1))
    #define RIGHTCHILD(i) ((2*i+2))
    vector<SegmentTreeNode> container; 
    int topNode; 
    SegmentTree(vector<int> &data, int t){
        //initializing construction then constructing the tree
        container = vector<SegmentTreeNode>(4*data.size());
        topNode=t; 
        construct(0,data.size()-1,data,0); 
    }
    void construct(int leftBound, int rightBound,vector<int>&data, int node){
        if(leftBound==rightBound){
            //reached a leaf node
            container[node].initialize(leftBound,rightBound,data[leftBound]);
            return; 
        }
        int midPoint = (leftBound+rightBound)/2; 
        //construct left child
        construct(leftBound,midPoint,data,LEFTCHILD(node));
        //construct right child
        construct(midPoint+1,rightBound,data,RIGHTCHILD(node)); 
        //construct the current node using children
        container[node].initialize(leftBound,rightBound,container[LEFTCHILD(node)].milkSet,container[RIGHTCHILD(node)].milkSet); 
    }
    //answers query in form of does range [left,right] contain this milk type?
    bool query(int qLeft, int qRight, int milk, int node){
        if(qLeft<=container[node].leftBound && qRight>=container[node].rightBound){
            //query completely encapsulates node's range
            return container[node].containsMilk(milk); 
        }else if((qLeft>=container[node].leftBound && qLeft<=container[node].rightBound) || qRight>=container[node].leftBound && qRight<=container[node].rightBound){
            //query is partially intersecting with node's range
            return query(qLeft,qRight,milk,LEFTCHILD(node)) || query(qLeft,qRight,milk,RIGHTCHILD(node));
        }
        return false; 
    }
};
struct Query{
    int qLeft;
    int qRight;
    int segmentTreeID; 
    Query(int bound1,int bound2, int id):segmentTreeID(id){
        qLeft=(bound1<bound2 ? bound1 : bound2);
        qRight=(bound1>bound2 ? bound1 : bound2);
    }; 
};
struct DecomposedNode{
    //stores which decomposed path a node belongs to as well the node's position in the segment tree of the decomposed path
    int segmentTreeID; //decomposition[segmentTreeID]
    int position; 
    DecomposedNode(){}
    DecomposedNode(int id, int p):segmentTreeID(id),position(p){}
};
int n,m; 
vector<vector<int>> tree; 
vector<SegmentTree> decomposition; //heavy-light decomposed paths of tree
int milks[MAX];
int levels[MAX]; //for binary lifting
int binaryParents[MAX][16]; //for binary lifting
int subtreeSizes[MAX]; //for heavy-light decomposition
DecomposedNode decomposedNodes[MAX]; 
void findSubtreeSize(bool visited[MAX], int node){
    visited[node]=true; 
    subtreeSizes[node]=1; 
    for(int i = 0; i < tree[node].size(); i++){
        if(!visited[tree[node][i]]){
            findSubtreeSize(visited,tree[node][i]); 
            subtreeSizes[node]+=subtreeSizes[tree[node][i]]; 
        }
    }
}
void decompose(bool visited[MAX], vector<int> &path, int &pos, int &topNode,int node){
    visited[node]=true; 
    decomposedNodes[node] = DecomposedNode(decomposition.size(),pos); 
    if(path.empty()){topNode=node;}
    path.push_back(milks[node]);
    sort(tree[node].begin(),tree[node].end(),[](const int& a, const int& b){
        return subtreeSizes[a] > subtreeSizes[b];
    });
    bool pathExtended=false;
    for(int i = 0; i < tree[node].size(); i++){
        if(!visited[tree[node][i]]){
            pathExtended=true;
            pos++;
            decompose(visited,path,pos,topNode,tree[node][i]); 
        }
    }
    if(!pathExtended){
        //leaf node reached; Path is complete
        decomposition.push_back(SegmentTree(path,topNode)); 
        pos=-1; 
        path.clear(); 
    }
}
//returns parent of node at 2^x levels above relative to node
int binaryParent(int node, int x){
    if(binaryParents[node][x]==-1 && x==0){
        return -1; 
    }
    else if(binaryParents[node][x]!=-1){
        return binaryParents[node][x];
     }else{
        binaryParents[node][x] = binaryParent(binaryParent(node,x-1),x-1);
        return binaryParents[node][x];
     } 
}
//returns parent of node at specified level above relative to node
int parent(int node, int level){
    int i = 0; 
    vector<int> binaryLevels; //breaking levels up by powers of 2
    while(i!=16){
        if(level & (1<<i))
            binaryLevels.push_back(i);
        i++; 
    }
    int parentNode = node; 
    for(i = 0; i < binaryLevels.size(); i++)
        parentNode = binaryParent(parentNode,binaryLevels[i]); 
    if(binaryLevels.empty())
        parentNode = binaryParent(node,0); 
    return parentNode; 
}
//returns the LCA between nodes a & b 
int findLCA(int a, int b){
    //swap to make sure a is higher node
    if(levels[b]<levels[a]){
        int temp = a; 
        a = b; 
        b = temp; 
    }
    //bring b to same level as a
    int heightDiff = levels[b] - levels[a];
    if(heightDiff!=0)
        b=parent(b,heightDiff); 
    if(a==b){return a;}
    int i = 0; 
    vector<int> binaryLevels; //breaking levels up by powers of 2
    while(i!=16){
        if(levels[a] & (1<<i))
            binaryLevels.push_back(i);
        i++; 
    }
    //binary lifting
    for(i = 0; i < binaryLevels.size(); i++){
        int parentA = parent(a,binaryLevels[i]); 
        int parentB = parent(b,binaryLevels[i]); 
        if(parentA!=parentB){
            a=parentA;
            b=parentB; 
        }
    }
    return binaryParent(a,0); 
}
//decomposes path from node to an ancestor node to multiple queries
bool decomposedQuery(int node, int ancestor, bool includeLCA, int milk){
    while(decomposedNodes[node].segmentTreeID!=decomposedNodes[ancestor].segmentTreeID){
        if(decomposition[decomposedNodes[node].segmentTreeID].query(decomposedNodes[decomposition[decomposedNodes[node].segmentTreeID].topNode].position,decomposedNodes[node].position,milk,0))
            return true; 
        node = binaryParents[decomposition[decomposedNodes[node].segmentTreeID].topNode][0];
        if(node==-1){return false;}
    }
    if(decomposition[decomposedNodes[node].segmentTreeID].query(decomposedNodes[ancestor].position,decomposedNodes[node].position,milk,0))
        return true;
    return false; 
}
void initializeBinaryLifting(bool visited[MAX], int node, int level){
    visited[node]=true;
    levels[node] = level; 
    for(int i = 0; i < tree[node].size(); i++){
        if(visited[tree[node][i]]){
            binaryParents[node][0] = tree[node][i]; 
        }else{
            initializeBinaryLifting(visited,tree[node][i],level+1); 
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin>>n>>m; 
    tree = vector<vector<int>>(n);
    for(int i = 0; i < n; i++)
        cin>>milks[i];
    for(int i = 0; i < n-1; i++){
        int a,b; cin>>a>>b; a--; b--; 
        tree[a].push_back(b);
        tree[b].push_back(a); 
    }
    //initialize binary lifting
    {
        //-1 represents uninitialized
        for(int r = 0; r < n; r++)
            for(int c = 0; c < 16; c++)
                binaryParents[r][c]=-1;
        bool visited[MAX] = {}; 
        initializeBinaryLifting(visited,0,0); 
    }
    //find subtree sizes of every node
    {
        bool visited[MAX] = {}; 
        findSubtreeSize(visited,0);
    }
    //create heavy-light decomposition of tree
    {
        bool visited[MAX] = {}; 
        vector<int> path; 
        int pos = 0;
        int topNode = 0;
        decompose(visited,path,pos,topNode,0); 
    }
    //answer queries
    for(int i = 0; i < m; i++){
        int a,b,c; cin>>a>>b>>c; a--; b--; 
        if(a==b){
            cout<<(decomposition[decomposedNodes[a].segmentTreeID].query(decomposedNodes[a].position,decomposedNodes[a].position,c,0)?"1":"0");
            continue;
        }
        //break up the query into multiple queries of the decomposed tree
        int LCA = findLCA(a,b);
        bool aIsLCA_Pair = decomposedNodes[a].segmentTreeID==decomposedNodes[LCA].segmentTreeID; 
        bool queryA = decomposedQuery(a,LCA,aIsLCA_Pair,c); 
        bool queryB = decomposedQuery(b,LCA,!aIsLCA_Pair,c); 
        cout<<(queryA||queryB?"1":"0"); 
    }
}    
/*
Node: 598, Ancestor: 23, SegmentTreeID: 0, Ancestor SegmentTreeID: 6
14 7
1 2 3 3 3 3 2 1 2 4 5 1 1 2
1 2
2 3
3 4
2 5
5 6
5 7
7 8
8 9
8 10
10 11
4 12
4 13
13 14
4 6 1
4 11 5
14 9 4
3 3 2
9 11 5
1 2 2
2 14 1

14 1
1 2 3 3 3 3 2 1 2 4 5 1 1 2
1 2
2 3
3 4
2 5
5 6
5 7
7 8
8 9
8 10
10 11
4 12
4 13
13 14
1 14 4

14 1
1 2 2 3 2 1 4 6 4 8 1 3 7 5
1 2
1 3
1 4
2 11
2 12
3 8
3 6
3 7
4 5
11 13
13 14
5 9 
5 10
8 12 5
*/