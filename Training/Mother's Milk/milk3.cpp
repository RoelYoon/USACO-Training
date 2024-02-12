/*
ID: roelyoon
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[20][20][20] = {{{}}}; 
int capacity[3];
vector<int> ans; 
void DFS(int a, int b, int c){
    if(visited[a][b][c] || a<0 || b<0 || c<0){
        return;
    }visited[a][b][c]=true;
    if(a==0){
        ans.push_back(c);
    }
    if(a>0){
        //pour a->b
        if(capacity[1]-b>a){DFS(0,b+a,c);}
        else{DFS(a-(capacity[1]-b),capacity[1],c);}
        //pour a->c
        if(capacity[2]-c>a){DFS(0,b,c+a);}
        else{DFS(a-(capacity[2]-c),b,capacity[2]);}
    }
    if(b>0){
        //pour b->a
        if(capacity[0]-a>b){DFS(a+b,0,c);}
        else{DFS(capacity[0],b-(capacity[0]-a),c);}
        //pour b->c
        if(capacity[2]-c>b){DFS(a,0,c+b);}
        else{DFS(a,b-(capacity[2]-c),capacity[2]);}
    }
    if(c>0){
        //pour c->a
        if(capacity[0]-a>c){DFS(a+c,b,0);}
        else{DFS(capacity[0],b,c-(capacity[0]-a));}
        //pour c->b
        if(capacity[1]-b>c){DFS(a,b+c,0);}
        else{DFS(a,capacity[1],c-(capacity[1]-b));}
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    int a,b,c; cin>>capacity[0]>>capacity[1]>>capacity[2];
    DFS(0,0,capacity[2]);
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]; if(i!=ans.size()-1){cout<<" ";}
    }
    cout<<"\n";
}
