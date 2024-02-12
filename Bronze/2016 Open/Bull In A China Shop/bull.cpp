#include <iostream>
#include <vector>
using namespace std;
int n,k;
bool inBounds(int r, int c){
    return r>=0 && r<n && c>=0 && c<n;
}
struct Piece{
    char grid[10][10];
    Piece(){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cin>>grid[r][c];
            }
        }
    }
    Piece(Piece &original, Piece &negator, int xOffset, int yOffset){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                grid[r][c] = original.grid[r][c];
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(inBounds(r+yOffset,c+xOffset) && original.grid[r+yOffset][c+xOffset]=='#' && negator.grid[r][c]=='#'){
                    grid[r+yOffset][c+xOffset] = '.';
                }
            }
        }
    }
};
bool match(Piece &original, Piece &piece, int xOffset, int yOffset){
    if(xOffset==1 && yOffset==0){
        bool lol = false;
    }
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(inBounds(r+yOffset,c+xOffset)
            && piece.grid[r][c]=='#'
            && original.grid[r+yOffset][c+xOffset]!='#'){
                return false;
            }else if(!inBounds(r+yOffset,c+xOffset)
            && piece.grid[r][c]=='#'){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("bcs.in","r",stdin);
    freopen("bcs.out","w",stdout);
    cin>>n>>k;
    Piece original;
    vector<Piece> pieces(k);
    for(int i = 0; i < k; i++){
        for(int x = -n+1; x < n; x++){
            for(int y = -n+1; y < n; y++){
                if(match(original,pieces[i],x,y)){
                    Piece halfNegatedOriginal(original,pieces[i],x,y);
                    for(int j = 0; j < k; j++){
                        for(int x2 = -n+1; x2 < n; x2++){
                            for(int y2 = -n+1; y2 < n; y2++){
                                if(match(original,pieces[j],x2,y2)){
                                    Piece fullNegatedOriginal(halfNegatedOriginal,pieces[j],x2,y2);
                                    bool found=true;
                                    for(int r = 0; r < n; r++){
                                        for(int c = 0; c < n; c++){
                                            if(fullNegatedOriginal.grid[r][c]=='#'){
                                                found=false;
                                                break;
                                            }
                                        }if(!found){break;}
                                    }
                                    if(found){
                                        cout<<(i<j?i:j)+1<<" "
                                        <<(i>j?i:j)+1<<"\n";
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
