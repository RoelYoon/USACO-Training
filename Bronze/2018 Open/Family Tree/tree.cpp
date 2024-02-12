#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Cow{
    string name;
    Cow* parent;
    unordered_set<string> children;
    Cow(){}
    Cow(string name):name(name){parent=nullptr;}
    void setParent(unordered_map<string,Cow>& cows,string& parentName){
        parent = &cows.find(parentName)->second;
    }
    void addChild(string& childName){
        children.insert({childName});
    }
};
int n;
string bessie, elsie, rootAncestor; 
unordered_map<string,Cow> cows;
bool siblingCheck(){
    Cow bess = cows.find(bessie)->second;
    return bess.parent != nullptr && bess.parent->children.find(elsie)!=bess.parent->children.end();
}
void parentCheck(string head, int& depth, bool flipped){
    if(head==(flipped?bessie:elsie)){
        return;
    }
    if(cows.find(head)->second.parent!=nullptr){
        depth++;
        parentCheck(cows.find(head)->second.parent->name,depth,flipped);
    }else{
        rootAncestor=head;
        depth=-1;
    }
}
void auntCheck(string& head, int& depth,bool flipped){
    if(cows.find(head)->second.children.find((flipped?bessie:elsie))!=cows.find(head)->second.children.end()){
        return;
    }
    if(cows.find(head)->second.parent!=nullptr){
        depth++;
        auntCheck(cows.find(head)->second.parent->name,depth,flipped);
    }else{
        rootAncestor=head;
        depth=-1;
    }
}
bool related(string head){
    if(head==elsie){
        return true; 
    }
    Cow headCow = cows.find(head)->second;
    bool isRelated=false; 
    for(unordered_set<string>::iterator it = headCow.children.begin(); it != headCow.children.end(); it++){
        if(related(*it)){
            return true;
        }
    }
    return false;
}
void answer(string relation,bool flipped){
    cout<<(flipped?bessie:elsie)<<" is the "<<relation<<" of "<<(flipped?elsie:bessie)<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("family.in","r",stdin);
    freopen("family.out","w",stdout);
    cin>>n>>bessie>>elsie;
    for(int i = 0; i < n; i++){
        string parent, child;
        cin>>parent>>child;
        if(cows.find(parent)==cows.end())
            cows[parent]=Cow(parent);
        if(cows.find(child)==cows.end())
            cows[child]=Cow(child);
        cows[parent].addChild(child);
        cows[child].setParent(cows,parent);
    }
    if(siblingCheck()){
        cout<<"SIBLINGS\n";
    }else{
        int depth=0;
        parentCheck(bessie,depth,0);
        if(depth==1){
            answer("mother",0);
        }
        else if(depth==2){
            answer("grand-mother",0);
        }else if(depth>2){
            string header = "";
            for(int i = 2; i < depth; i++){
                header+="great-";
            }
            answer(header+"grand-mother",0);
        }else{
            depth=0;
            auntCheck(bessie,depth,0);
            if(depth==2){
                answer("aunt",0);
            }
            else if(depth>2){
                string header = "";
                for(int i = 2; i < depth; i++){
                    header+="great-";
                }
                answer(header+"aunt",0);
            }else{
                if(related(rootAncestor)){
                    depth=0;
                    parentCheck(elsie,depth,1);
                    if(depth==1){
                        answer("mother",1);
                    }
                    else if(depth==2){
                        answer("grand-mother",1);
                    }else if(depth>2){
                        string header = "";
                        for(int i = 2; i < depth; i++){
                            header+="great-";
                        }
                        answer(header+"grand-mother",1);
                    }else{
                        depth=0;
                        auntCheck(elsie,depth,1);
                        if(depth==2){
                            answer("aunt",1);
                        }
                        else if(depth>2){
                            string header = "";
                            for(int i = 2; i < depth; i++){
                                header+="great-";
                            }
                            answer(header+"aunt",1);
                        }else{
                            cout<<"COUSINS\n";
                        }
                    }
                }else{
                    cout<<"NOT RELATED\n";
                }
            }
        }
    }
}
