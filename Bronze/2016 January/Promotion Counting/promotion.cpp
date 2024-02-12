#include <iostream>
using namespace std;
int main(){
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    int promotion[5]{0,0,0,0,0};
    int initial[4];
    int final[4];
    for(int i = 0; i < 4; i++)
        cin>>initial[i]>>final[i];
    for(int i = 3; i >0 ; i--)
        promotion[i]=final[i]-(initial[i]-promotion[i+1]);
    for(int i = 1; i < 4; i++)
        cout<<promotion[i]<<"\n";
}
