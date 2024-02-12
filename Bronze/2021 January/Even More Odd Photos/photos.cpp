#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    int even = 0;
    int odd = 0; 
    for(int i = 0; i < n; i++){
        int temp; cin>>temp;
        bool parity = temp%2==0; 
        even+=parity;
        odd+=!parity; 
    }
    int groups = 0; 
    bool state = 0; //0-even 1-odd
    while(1){
        switch(state){
            case false:
                //even
                if(even>0){
                    even--; 
                    groups++;
                }else if(odd>1){
                    odd-=2; 
                    groups++; 
                }else{
                    goto exit; 
                }
                break;
            case true:
                //odd
                if(odd>0){
                    odd--; 
                    groups++;
                }else{
                    goto exit; 
                }
                break;
        }
        state=!state; 
    }
    exit: 
    if(odd>0){
        groups--; 
    }
    cout<<groups<<"\n"; 
}