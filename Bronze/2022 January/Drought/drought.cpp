/*
ID: roelyoon
TASK: drought
LANG: C++    
*/
#include <stdio.h>
#include <memory>
#include <vector> 
#include <unordered_map>
#define PARENT(i) (i-1)/2
#define LEFT(i) (2*i)+1
#define RIGHT(i) (2*i)+2
typedef long long ll;
using namespace std;
struct element{
    shared_ptr<element> left,right;
    ll value;
    int key; 
};
unordered_map<int, int> keyToIndex;
struct binary_heap{
    vector<shared_ptr<element>> pq; 
    shared_ptr<element> top(){
        return pq[0];
    }
    void updatePair(ll &min, ll &trueMin, ll &count){
        shared_ptr<element> bigPair,smallPair; 
        if(pq[0]->left==NULL){bigPair=pq[0]->right; smallPair=pq[0]->right;}
        else if(pq[0]->right==NULL){bigPair=pq[0]->left; smallPair=pq[0]->left;}
        else{
            if(pq[0]->left->value>pq[0]->right->value){
                bigPair=pq[0]->left;
                smallPair=pq[0]->right;
            }else{
                bigPair=pq[0]->right;
                smallPair=pq[0]->left;
            }
        }
        ll update = pq[0]->value - min;
        pq[0]->value-=update;
        ll bigX = bigPair->value-min;
        ll smallX = smallPair->value-min;
        if(update>bigX){
            bigPair->value-=bigX;

        }else{
            bigPair->value-=update;s
        }
        count+=update*2;
        if(smallPair->value < trueMin){trueMin=smallPair->value;}
        else if(bigPair->value < trueMin){trueMin=bigPair->value;}
        siftDown(bigPair);
        siftDown(smallPair);
        siftDown(top());
    }
    void swap(shared_ptr<element> a, shared_ptr<element> b){
        int indA = keyToIndex[a->key];
        int indB = keyToIndex[b->key];
        keyToIndex[a->key]=indB;
        keyToIndex[b->key]=indA;
        shared_ptr<element> temp = pq[indB];
        pq[indB] = pq[indA];
        pq[indA] = temp; 
    }
    void siftDown(shared_ptr<element> item){
        int i=keyToIndex[item->key],leftI, rightI;
        while(true){
            leftI=LEFT(i);
            rightI=RIGHT(i);
            if(leftI>pq.size()-1 && rightI>pq.size()-1){break;}
            else if(leftI>pq.size()-1&&pq[rightI]->value>=pq[i]->value){swap(pq[i],pq[rightI]);i=rightI;}
            else if(rightI>pq.size()-1&&pq[leftI]->value>=pq[i]->value){swap(pq[i],pq[leftI]);i=leftI;}
            else if(leftI<pq.size()&&rightI<pq.size()&&pq[leftI]->value>pq[rightI]->value &&pq[leftI]->value>=pq[i]->value){swap(pq[i],pq[leftI]);i=leftI;}
            else if(leftI<pq.size()&&rightI<pq.size()&&pq[rightI]->value>=pq[leftI]->value &&pq[rightI]->value>=pq[i]->value){swap(pq[i],pq[rightI]);i=rightI;}
            else{break;}
        }
    }
    void insert(shared_ptr<element> item){
        pq.push_back(item);
        int i = pq.size()-1, parent; 
        keyToIndex[item->key]=i;
        while(true){
            parent = PARENT(i);
            if(pq[i]->value>pq[parent]->value){
                swap(pq[i],pq[parent]);
                i=parent;
            }else{break;}
            if(i==0){break;}
        }
        keyToIndex[item->key]=i;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    for(int test = 0; test<t; test++){
        int n;
        ll count = 0; 
        scanf("%d",&n);
        vector<shared_ptr<element>> hungerList(n); 
        binary_heap heap;
        for(int i = 0; i < n; i++){
            shared_ptr<element> temp(new element);
            scanf("%lld",&(temp->value));
            temp->key=i;
            hungerList[i]=temp;
        } if(n==1){printf("0\n");continue;}
        for(int i = 0; i < n; i++){
            shared_ptr<element> temp = hungerList[i]; 
            if(i!=0){temp->left = hungerList[i-1];}
            else{temp->left=NULL;}
            if(i!=n-1){temp->right = hungerList[i+1];}
            else{temp->right=NULL;}
            heap.insert(temp);
        }
        ll min = hungerList[0]->value;
        for(int i = 1; i < n; i++){
            if(hungerList[i]->value<min){
                min=hungerList[i]->value;
            }
        }
        ll trueMin = min;
        while(true){
            heap.updatePair(min, trueMin, count);
            if(trueMin<0){
                count=-1;
                break;
            }
            if(heap.top()->value==min){min=trueMin;}
            if(heap.top()->value==trueMin){break;}
        }
        for(int i = 0; i < heap.pq.size();i++){
            printf("%lld ",heap.pq[keyToIndex[i]]->value);
        }
        printf("%lld\n",count);
    }
}
/* naive
#include <stdio.h>
#define MAX 1000000005
typedef long long ll;
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int test = 0; test<t; test++){
        int n; 
        scanf("%d",&n);
        ll hunger[100005];
        ll min=MAX; 
        for(int i = 0; i < n; i++){
            scanf("%lld",&hunger[i]);
            if(hunger[i]<min){
                min=hunger[i];
            }
        }
        bool possible = true;
        ll count = 0;
        while(possible){
            bool allEqual = true;
            for(int i = 0; i < n; i++){
                if(hunger[i]!=min){
                    int largestNeighbor=-1;
                    allEqual=false;
                    if(i!=0){
                        largestNeighbor=i-1; 
                    }
                    if(i!=n-1 && hunger[i+1]>=hunger[largestNeighbor] || largestNeighbor==-1){
                        largestNeighbor=i+1;
                    }
                    ll delta = hunger[i]-min; 
                    count+=delta;
                    hunger[i]-=delta;
                    hunger[largestNeighbor]-=delta;
                    if(hunger[largestNeighbor]<min){
                        min=hunger[largestNeighbor];
                        break;
                    }
                }
            }
            if(min<0){possible=false;}
            if(allEqual){break;}
        }
        if(possible){printf("%lld\n",count*2);}
        else{printf("%d\n",-1);}
    }
    return 0;
}
*/