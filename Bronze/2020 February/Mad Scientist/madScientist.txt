#include <iostream>
#include <bitset> 
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    int n; cin>>n;
    bitset<1000> aSet,bSet; 
    string a,b;
    cin>>a>>b;
    for(int i = 0; i < n; i++){
        if(a[i]=='G'){aSet[i]=0;}
        else{aSet[i]=1;}
    }
    for(int i = 0; i < n; i++){
        if(b[i]=='G'){bSet[i]=0;}
        else{bSet[i]=1;}
    }
    bitset<1000> XOR = aSet^bSet; 
    bool state = XOR[0]; 
    int count = state; 
    for(int i = 1; i < n; i++){
        if(XOR[i]==1){
            //unmatching
            if(!state){
                count++; 
                state=!state; 
            }
        }else{
            if(state){
                state=!state; 
            }; 
            //matching
        }
    }
    cout<<count<<endl; 
}