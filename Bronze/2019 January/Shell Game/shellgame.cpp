#include <iostream>
#include <vector>
using namespace std;
int n;
struct Step{
    int a;
    int b;
    int g;
    Step(){cin>>a>>b>>g;a--;b--;g--;}
};
int simulate(bool shells[3],vector<Step> &steps){
    int points = 0;
    for(int i = 0; i < n; i++){
        bool temp = shells[steps[i].a];
        shells[steps[i].a] = shells[steps[i].b];
        shells[steps[i].b] = temp;
        if(shells[steps[i].g])
            points++;
    }
    return points; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);
    cin>>n;
    vector<Step> steps(n);
    int maxPoints=0;
    bool shells[3]{1,0,0};
    maxPoints=max(maxPoints,simulate(shells,steps));
    shells[0]=0;shells[1]=1;shells[2]=0;
    maxPoints=max(maxPoints,simulate(shells,steps));
    shells[0]=0;shells[1]=0;shells[2]=1;
    maxPoints=max(maxPoints,simulate(shells,steps));
    cout<<maxPoints<<"\n";
}