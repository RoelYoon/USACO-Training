#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    cin>>n;
    int state[105];
    for(int i = 0; i < n; i++){
        cin>>state[i];
    }
    state[0]=0;
    for(int i = 0; i < n; i++){
        if(state[0]!=-1){
            for(int j = 1; j <= state[i]; j++){
                if(state[i-j]!=-1&&state[i-j]!=state[i]-j){cout<<-1<<"\n";return 0;}
                state[i-j] = state[i]-j;
            }
        }
    }
    int breakouts = 0;
    int dif = 0;
    for(int i = 0; i < n; i++){
        breakouts+=state[i]==0?1:0;
        dif+=state[i]==-1?1:0;
    }
    cout<<breakouts<<" "<<breakouts+dif<<"\n";
}