#include <iostream>
using namespace std;
int stackX[1000][1000]{},stackY[1000][1000]{},stackZ[1000][1000]{};
int n;
int size(int L){
    return max(0,L-n+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Q,cnt=0;
    cin>>n>>Q;
    for(int i=0;i<Q;++i){
        int x,y,z; cin>>x>>y>>z;
        cnt-=size(stackX[y][z]);
        ++stackX[y][z];
        cnt+=size(stackX[y][z]);

        cnt-=size(stackY[x][z]);
        ++stackY[x][z];
        cnt+=size(stackY[x][z]);

        cnt-=size(stackZ[x][y]);
        ++stackZ[x][y];
        cnt+=size(stackZ[x][y]);

        cout<<cnt<<"\n";
    }
}