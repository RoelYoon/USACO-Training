#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
struct Cow{
    int id;
    int priority;
    bool fixed;
    int position;
    Cow(){
        static int staticID = 0;
        id=staticID++;
        priority=-1;
        fixed=false;
        position=-1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    cin>>n>>m>>k; 
    vector<Cow> cows(n);
    vector<Cow*> heirarchy(m,nullptr);
    vector<Cow*> line(n,nullptr);
    for(int i = 0; i < m; i++){
        int id;
        cin>>id;
        heirarchy[i]=&cows[id-1];
        heirarchy[i]->priority=i;
    }
    for(int i = 0; i < k; i++){
        int id, pos; 
        cin>>id>>pos;
        cows[id-1].position = pos-1;
        cows[id-1].fixed=true;
        line[pos-1]=&cows[id-1];
        if(id-1==0){
            cout<<pos<<endl;
            return 0;
        }
    }
    int linePos = n-1;
    for(int i = m-1; i >=0; i--){
        if(heirarchy[i]->position!=-1){
            linePos = heirarchy[i]->position;
            continue;
        }
        while(line[linePos]!=nullptr){
            linePos--;
        }
        line[linePos]=heirarchy[i];
        heirarchy[i]->position=linePos;
    }
    int start = 0;
    int freeSpaceCount=0;
    if(cows[0].priority!=-1){
        for(int i = 0; i < m; i++){
            if(heirarchy[i]->id==0){
                break;
            }
            if(heirarchy[i]->fixed){
                start=heirarchy[i]->position+1;
                freeSpaceCount=i+1;
            }
        }
    }
    for(int i = start; i < (cows[0].priority!=-1 ? cows[0].position+1 : n); i++){
        if(cows[0].priority!=-1){
            if(line[i]==nullptr || (line[i]->priority!=-1 && (line[i]->priority <= cows[0].priority))){
                freeSpaceCount++;
            }
            if(freeSpaceCount==cows[0].priority+1){
                cout<<i+1<<endl;
                return 0;
            }
        }
        else if(line[i]==nullptr){
            cout<<i+1<<endl;
            return 0;
        }
    }
}