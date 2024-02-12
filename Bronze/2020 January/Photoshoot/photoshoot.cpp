#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    cin>>n;
    int line[1005];
    for(int i = 0; i < n-1; i++){
        cin>>line[i];
    }
    for(int i = 1; i <= n; i++){
        bool used[1005]{};
        string optimal = to_string(i);
        int prev = i;
        used[i]=true;
        for(int j = 0; j < n-1; j++){
            int pair = line[j] - prev;
            if(pair<0 || pair>n || used[pair]){break;}
            optimal+=" "+to_string(pair);
            prev = pair;
            used[prev] = true;
            if(j==n-2){
                cout<<optimal<<"\n";
                return 0;
            }
        }
    }
}