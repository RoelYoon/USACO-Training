#include <iostream>
using namespace std;
struct Location{
    int q;
    //0 - jump pad
    //1 - target
    //2 - broken target
    //-1 uninitialized
    int v;
    Location():q(-1){}
};
int n, s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Location locations[100005];
    int n; cin>>n>>s;
    for(int i = 1; i <= n; i++){
        cin>>locations[i].q>>locations[i].v;
    }
    bool dir = 1; 
    // 0 - reverse
    // 1- forward
    int cur = s;
    int k = 1;
    int i = 0; 
    int cnt = 0;
    while(cur<=n && cur>=1){
        Location* l = &locations[cur];
        if(l->q==0){
            // jump pad
            dir=!dir;
            k+=l->v;
        }else if(l->q==1){
            //target
            if(l->v <= k){
                cnt++;
                l->q=2;
            }
        }
        cur+=(dir?k:-k);
        i++;
        if(i>500000){break;};
    }
    cout<<cnt<<"\n";
}