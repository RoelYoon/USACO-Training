#include <iostream>
#include <vector>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    cin>>n>>m;
    string spottyGenomes[100];
    string plainGenomes[100];
    for(int i = 0; i < n; i++)
        cin>>spottyGenomes[i];
    for(int i = 0; i < n; i++)
        cin>>plainGenomes[i];
    bool notPossible[100]{};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                if(spottyGenomes[i][j]==plainGenomes[k][j]){
                    notPossible[j]=true;
                    break;
                }
            }
        }
    }
    int count=0;
    for(int i = 0; i < m; i++){
        if(!notPossible[i]){
            count++;
        }
    }
    cout<<count<<"\n";
}
