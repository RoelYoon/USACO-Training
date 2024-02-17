#include <iostream>
#include <vector>
using namespace std;
int R,C;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>R>>C;
    vector<string> grid(R);
    vector<vector<int>> score(R,vector<int>(C,0));
    for(int i = 0; i < R; i++){
        cin>>grid[i];
    }
    int maxScore = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(grid[r][c]=='G'){
                if(r>0)
                    score[r][c]+=grid[r-1][c]=='C';
                if(r<R-1)
                    score[r][c]+=grid[r+1][c]=='C';
                if(c>0)
                    score[r][c]+=grid[r][c-1]=='C';
                if(c<C-1)
                    score[r][c]+=grid[r][c+1]=='C';
                maxScore+=score[r][c]>=2;
                if(score[r][c]==2){
                    if(r>0 && c>0 && grid[r-1][c]=='C' && grid[r][c-1]=='C' && grid[r-1][c-1]=='G' && score[r-1][c-1]==2){
                        maxScore--;
                    }else if(r>0 && c<C-1 && grid[r-1][c]=='C' && grid[r][c+1]=='C' && grid[r-1][c+1]=='G' && score[r-1][c+1]==2){
                        maxScore--;
                    }
                }
            } 
        }
    }
    cout<<maxScore<<"\n";
}