#include <iostream>
#include <vector> 
using namespace std;
void flip(vector<string> &farm, int rP, int cP){
    for(int r = 0; r <= rP; r++){
        for(int c = 0; c <= cP; c++){
            farm[r][c] = (farm[r][c]=='1' ? '0' : '1');
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int n; cin>>n;
    vector<string> farm(n); 
    for(int i = 0; i < n; i++){
        cin>>farm[i];
    }
    int count = 0; 
    for(int r = n-1; r>=0; r--){
        for(int c = n-1; c>=0; c--){
            if(farm[r][c]=='1'){
                count++;
                flip(farm,r,c); 
            }
        }
    }
    cout<<count<<"\n";
}
