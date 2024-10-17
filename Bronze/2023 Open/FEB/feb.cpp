#include <iostream>
#include <vector>
using namespace std;
struct OptionGate{
    int begin;
    int end;
    bool edge=0;
    OptionGate(){}
    OptionGate(int size, bool same){
        size+=2;
        bool odd=size%2;
        if(odd && same){
            begin=0; end=size-1;
        }else if(odd && !same){
            begin=1; end=size-2;
        }else if(!odd && same){
            begin=1; end=size-1;
        }else if(!odd && !same){
            begin=0; end=size-2;
        }
    }
    OptionGate(int s):edge(1){
        begin=0;
        end=s;
    }
};
int n;
string s;
vector<OptionGate> gates;
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    int B=0,E=0,F=0,base=0;
    char start;
    for(int i = 0; i < n; ++i){
        if(s[i]=='F'){
            if(!F)
                start=s[(i-1)<0?0:i-1];
            ++F;
            if(i==n-1){
                //edge finish
                gates.emplace_back(F);
                F=0;
            }else if(s[i+1]!='F'){
                //check if start edge
                if(i-(F-1)==0){
                    gates.emplace_back(F);
                }else{
                    gates.emplace_back(F,start==s[i+1]);
                }
                F=0;
            }
            B=0;
            E=0;
        }else{
            if(s[i]=='B'){
                E=0;
                ++B;
            }else{
                B=0;
                ++E;
            }
            base+=B>=2||E>=2;
        }
    }
    int minV=0,maxV=0;
    for(int i = 0; i < gates.size(); ++i){
        minV+=gates[i].begin;
        maxV+=gates[i].end;
    }
    if(gates.empty()||n==1){cout<<"1\n"<<base<<"\n"; return 0;}
    if(maxV-minV==n){
        cout<<maxV<<"\n";
        for(int i = 0; i < maxV; ++i){
            cout<<i<<"\n";
        }
        return 0;
    }
    if(gates[0].edge || gates[gates.size()-1].edge){
        for(int i = minV; i <= maxV; ++i){
            ans.push_back(base+i);
        }
    }else{
        for(int i = minV; i <= maxV; i+=2){
            ans.push_back(base+i);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i]<<"\n";
    }
}
/*
even & diff || odd & same
BFFE n=2
BFFFB n=3
{0,2,4,6...n-1}

even & same || odd & diff 
BFFB n=2
BFFFE n=3
{1,3,5,7...n-1}

edge
BF n=1
FE n=1
{0,1,2,3,4...n}

{0,1}+{1}+{1}

2
3

5
BBFFF
*/