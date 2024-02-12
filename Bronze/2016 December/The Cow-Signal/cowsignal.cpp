#include <iostream>
using namespace std;
int m,n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    cin>>m>>n>>k;
    char signal[10][10]{{}};
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            cin>>signal[r][c];
        }
    }
    int accessR = 0;
    for(int r = 0; r < m*k; r++){
        int accessC = 0;
        accessR+=r!=0&&r%k==0?1:0;
        for(int c = 0; c < n*k; c++){
            accessC+=c!=0&&c%k==0?1:0;
            cout<<signal[accessR][accessC];
        }
        cout<<"\n";
    }
}
