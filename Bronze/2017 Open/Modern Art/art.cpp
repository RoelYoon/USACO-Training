#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("art.in","r",stdin);
    freopen("art.out","w",stdout);
    cin>>n;
    vector<string> grid(n);
    for(int i=0; i<n; i++)
        cin>>grid[i];
    int rowL[10]{11,11,11,11,11,11,11,11,11,11};
    int rowH[10]{};
    int colL[10]{11,11,11,11,11,11,11,11,11,11};;
    int colH[10]{};
    bool first[10]{};
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int color = grid[r][c]-48;
            first[color]=true;
            rowL[color]=(r<rowL[color]?r:rowL[color]);
            colL[color]=(c<colL[color]?c:colL[color]);
            rowH[color]=(r>rowH[color]?r:rowH[color]);
            colH[color]=(c>colH[color]?c:colH[color]);
        }
    }
    for(int color = 1; color <= 9; color++)
        for(int r = rowL[color]; r<=rowH[color]; r++)
            for(int c = colL[color]; c<=colH[color]; c++)
                if(grid[r][c]-48!=color)
                    first[grid[r][c]-48]=false;
    int cnt = 0;
    for(int i = 1; i < 10; i++)
        if(first[i])
            cnt++;
    cout<<cnt<<"\n";
}