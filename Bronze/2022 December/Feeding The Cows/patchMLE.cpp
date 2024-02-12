#include <iostream>
#include <vector> 
#include <string>
#define MAX 100005
using namespace std;
int n,k; 
string s, patchS;
int infG[MAX]; 
int infH[MAX]; 
struct SegmentTree{
    #define PARENT(i) ((i-1)/2)
    #define LEFT(i) (2*i+1)
    #define RIGHT(i) (2*i+2)
    vector<int> container;
    SegmentTree(char type){
        container = vector<int>(4*n); 
        construct(type,0,n-1,0); 
    }
    SegmentTree(char type, int data[MAX]){
        container = vector<int>(4*n); 
        construct(type,0,n-1,0,data); 
    }
    void construct(char type,int l, int r, int node){
        if(l==r){
            //leaf node
            container[node] = (s[l]==type ? 1 : 0); 
            return;
        }
        int mid = (l+r)/2; 
        construct(type,l,mid,LEFT(node));
        construct(type,mid+1,r,RIGHT(node));
        container[node] = container[LEFT(node)] + container[RIGHT(node)]; 
    }
    void construct(char type,int l, int r, int node, int data[MAX]){
        if(l==r){
            //leaf node
            container[node] = (data[l]>0 ? 1 : 0); 
            return;
        }
        int mid = (l+r)/2; 
        construct(type,l,mid,LEFT(node));
        construct(type,mid+1,r,RIGHT(node));
        container[node] = container[LEFT(node)] + container[RIGHT(node)]; 
    }
    int queryRecursion(int qL, int qR, int l, int r, int node){
        if(qL<=l && r<=qR){
            //completely covered
            return container[node]; 
        }else if(qL>r || qR<l){
            //out of bounds
            return 0; 
        }else{
            int mid = (l+r)/2; 
            return queryRecursion(qL,qR,l,mid,LEFT(node)) + queryRecursion(qL,qR,mid+1,r,RIGHT(node)); 
        }
    }
    //answers query of form how many type t in range [qL,qR]
    int query(int qL, int qR){
        return queryRecursion(qL,qR,0,n-1,0);
    }
    void updateRecursion(int l, int r, int node, int pos, int count){
        if(l==r){
            container[node]-=count; 
            return; 
        }
        else if(pos>=l && pos<=r){
            // covered
            int mid = (l+r)/2; 
            updateRecursion(l,mid,LEFT(node),pos,count);
            updateRecursion(mid+1,r,RIGHT(node),pos,count);
            container[node] = container[LEFT(node)] + container[RIGHT(node)];
        }else{
            return;
        }
    }
    void update(int pos, int count){
        updateRecursion(0,n-1,0,pos,count);
    }
};
void markPatches(char type, SegmentTree &segTree, int inf[MAX], string &p, int &count){
    //find relative area
    SegmentTree infTree(type,inf);
    int areaLeftBound=0;
    int areaRightBound=areaLeftBound; 
    int size = 0; 
    for(int i = 0; i < n; i++){
        if(s[i]==type || size==2*k){
            if(segTree.query(i,i+2*k)==1 || size==2*k){
                areaRightBound=i;
                int largeLeft=areaLeftBound, largeRight=largeLeft; 
                int max = 0; 
                for(int j = areaLeftBound; j < areaRightBound; j++){
                    if(inf[j]>max){
                        largeLeft = j; 
                        max=inf[j];
                    }if(inf[j]==max){
                        largeRight = j;
                    }
                }
                int lInf = infTree.query(largeLeft-2*k,largeLeft+2*k); 
                int rInf = infTree.query(largeRight-2*k,largeRight+2*k);
                int pos = (lInf > rInf ? largeLeft : largeRight); 
                if(p[pos]=='.'){p[pos] = type;}
                else{p[pos+1]=type;}
                count++;
                for(int i = pos-k; i <= pos+k; i++){
                    int l = i - k; l = (l<0 ? 0 : l); 
                    int r = i + k; r = (r>n-1 ? n-1 : r);  
                    int amount=segTree.query(l,r);
                    inf[i]-=amount;
                    infTree.update(i,amount); 
                }
                areaLeftBound=areaRightBound+1;
                size = 0;
            }
        }
        size++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; 
    while(t--){
        cin>>n>>k>>s;
        if(k==0){
            cout<<n<<"\n"<<s<<"\n";
            continue;
        }
        SegmentTree GTree('G');
        SegmentTree HTree('H');
        for(int i = 0; i < n; i++){
            int l = i - k; l = (l<0 ? 0 : l); 
            int r = i + k; r = (r>n-1 ? n-1 : r);  
            infG[i] =GTree.query(l,r);
            infH[i] = HTree.query(l,r);
        }
        string patch = ""; for(int i = 0; i < n; i++){patch+='.';}
        int patchCount = 0; 
        markPatches('G',GTree,infG,patch,patchCount);
        markPatches('H',HTree,infH,patch,patchCount); 
        cout<<patchCount<<"\n"<<patch<<"\n";
    }
}
/*
k=2
GHHGG
.HG..
k=1
GHHGG
GH.G.
*/