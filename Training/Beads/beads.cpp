/*
ID: roelyoon
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector> 
#include <string>
using namespace std;
struct Segment{
    unordered_map<string, int>  whiteSegments; 
    char type;
    int size; 
    int pos; 
    Segment(char t, int s):type(t),size(s){}
    Segment(char t, int s, unordered_map<string,int> w):type(t),size(s),whiteSegments(w){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("beads.in","r",stdin);
    //freopen("beads.out","w",stdout);
    int n; cin>>n; 
    string bead; cin>>bead;a
    vector<Segment> unmergedSegments; 
    char type = bead[0]; 
    int size = 1;
    //separating segments by color
    for(int i = 1; i < n; i++){
        if(bead[i] == type){
            size++; 
        }else{
            unmergedSegments.push_back(Segment(type,size));
            type = bead[i];
            size = 1; 
        }
    }
    if(unmergedSegments.size()==0){cout<<n<<"\n"; return 0;}
    //checking if end segments are connected
    if(type == unmergedSegments[0].type){
        unmergedSegments[0].size+=size; 
    }else{
        unmergedSegments.push_back(Segment(type,size));
    }
    vector<Segment*> segments; //filtered of whites
    for(int i = 0; i < unmergedSegments.size(); i++){
        if(unmergedSegments[i].type == 'w'){
            int size = unmergedSegments[i].size;
            string id = to_string((i)) + "-" + to_string((i+size-1));
            unmergedSegments[((i==0)?unmergedSegments.size()-1:i-1)].size+=size; 
            unmergedSegments[((i==0)?unmergedSegments.size()-1:i-1)].whiteSegments[id] = size; 
            unmergedSegments[((i==unmergedSegments.size()-1)?0:i+1)].size+=size; 
            unmergedSegments[((i==unmergedSegments.size()-1)?0:i+1)].whiteSegments[id] = size; 
        }else{
            segments.push_back(&unmergedSegments[i]); 
        }
    }
    if(segments.size()<=2){cout<<n<<"\n"; return 0;}
    vector<Segment> mergedSegments; //all parts merged & finalized
    Segment* cur = segments[0];
    size = cur->size;
    unordered_map<string, int> whiteSegments = cur->whiteSegments;
    for(int i = 1; i < segments.size(); i++){
        if(segments[i]->type == cur->type){
            size+=segments[i]->size; 
            unordered_map<string,int>::iterator it = whiteSegments.begin();
            for(;it!=whiteSegments.end();it++){
                if(segments[i]->whiteSegments.find(it->first)!=segments[i]->whiteSegments.end()){
                    size-=it->second;
                }
            }
            whiteSegments.insert(segments[i]->whiteSegments.begin(),segments[i]->whiteSegments.end());
        }else{
            mergedSegments.push_back(Segment(cur->type,size,whiteSegments));
            cur = segments[i];
            size = segments[i]->size; 
            whiteSegments = segments[i]->whiteSegments;
        }
    }
    if(cur->type == mergedSegments[0].type){
        mergedSegments[0].size+=size; 
        unordered_map<string,int>::iterator it = mergedSegments[0].whiteSegments.begin();
        for(;it!=mergedSegments[0].whiteSegments.end();it++){
            if(whiteSegments.find(it->first)!=whiteSegments.end()){
                mergedSegments[0].size-=it->second;
            }
        }
        mergedSegments[0].whiteSegments.insert(whiteSegments.begin(),whiteSegments.end());
    }else{
        mergedSegments.push_back(Segment(cur->type,size,whiteSegments));
    }
    if(mergedSegments.size()<=2){cout<<n<<"\n"; return 0;}
    int max = 0;
    for(int i = 0; i < mergedSegments.size(); i++){
        int j = (i==mergedSegments.size()-1) ? 0 : i+1;
        Segment a = mergedSegments[i];
        Segment b = mergedSegments[j]; 
        int val = a.size + b.size; 
        unordered_map<string,int>::iterator it = a.whiteSegments.begin();
        for(;it!=a.whiteSegments.end();it++){
            if(b.whiteSegments.find(it->first)!=b.whiteSegments.end()){
                val-=it->second;
            }
        }
        if(val>max){max=val;}
    }
    cout<<max<<"\n";
    return 0;
}