#include <stdio.h>
#include <math.h>
#include <unordered_map> 
#include <limits.h>
using namespace std; 
typedef long long LL;
int n;
struct Cow{
    int x;
    int y;
};
int find(int (&unions)[100005], int head){
    if(unions[head]==head){return head;}
    int ans = find(unions,unions[head]);
    unions[head] = ans;
    return ans; 
}
void unite(int (&unions)[100005], int a, int b){
    unions[b]=find(unions,a);
}
void Prim(Cow (&cows)[100005], unordered_map<int,int> &toInclude, int (&unions)[100005], LL& cost, int head,int depth){
    if(toInclude.find(head)==toInclude.end() || depth==n-1){return;}
    toInclude[head]--; 
    if(toInclude[head]==0){toInclude.erase(head);}
    Cow cur = cows[head]; 
    LL minCost = LLONG_MAX;
    int next = head;
    for(unordered_map<int,int>::iterator it = toInclude.begin(); it!=toInclude.end(); it++){
        int i = it->first; 
        LL c = pow(abs(cur.x-cows[i].x),2) + pow(abs(cur.y-cows[i].y),2);
        if(i!=head && c<minCost && find(unions,head)!=find(unions,i)){
            minCost = c; 
            next=i; 
        }
    }
    toInclude[next]--;
    unite(unions,head,next);
    cost+=minCost; 
    printf("%d %d : %lld : %lld\n",head,next,minCost,cost);
    Prim(cows,toInclude,unions,cost,next,depth+1);
}
int main(){
    scanf("%d",&n);
    Cow cows[100005];
    int unions[100005]; 
    unordered_map<int,int> toInclude; 
    for(int i = 0; i < n; i++){
        scanf("%d%d",&cows[i].x,&cows[i].y); //cin>>cows[i].x>>cows[i].y; 
        toInclude.insert({i,2});
        unions[i]=i;
    }
    LL cost = 0;
    Prim(cows,toInclude,unions,cost,0,0);
    printf("%lld\n",cost); //cout<<cost-1<<"\n";
}