#include <iostream>
#include <vector>
#include <unordered_set>
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
                //grid[r][c]=inBounds(r+yOffset,c+xOffset)&&negator.grid[r][c]=='#'?'.':original.grid[r][c];
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
class NoMatchFound : public std::exception {
    public:
    string what () {
        return "No Matching Piece";
    }
};
struct ReturnPayload{
    int matchedPieceID;
    int xOffset;
    int yOffset;
    ReturnPayload(int i, int x, int y):matchedPieceID(i),xOffset(x),yOffset(y){}
};
ReturnPayload findMatchingPiece(Piece &original, vector<Piece> &pieces, unordered_set<int>& ignore, int pair){
    for(int i = 0; i < k; i++){
        if(ignore.find(i)!=ignore.end() || i==pair){continue;}
        for(int x = -n+1; x < n; x++){
            for(int y = -n+1; y < n; y++){
                if(match(original,pieces[i],x,y)){
                    return ReturnPayload(i,x,y);
                }
            }
        }
    }
    throw NoMatchFound();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("bcs.in","r",stdin);
    //freopen("bcs.out","w",stdout);
    cin>>n>>k;
    Piece original;
    vector<Piece> pieces(k);
    unordered_set<int> failedPieces;
    unordered_set<int> secondMatchingFailedPieces;
    int failedMatchCount[10]{};
    while(true){
        ReturnPayload matching = findMatchingPiece(original,pieces,failedPieces,-1);
        Piece halfNegatedOriginal(original, pieces[matching.matchedPieceID], matching.xOffset, matching.yOffset);
        try{
            ReturnPayload secondMatching = findMatchingPiece(original,pieces,secondMatchingFailedPieces,matching.matchedPieceID);
            Piece fullNegatedOriginal(halfNegatedOriginal,pieces[secondMatching.matchedPieceID],secondMatching.xOffset,secondMatching.yOffset);
            bool found = true;
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    if(fullNegatedOriginal.grid[r][c]=='#'){
                        found=false;
                        break;
                    }
                }if(!found){break;}
            }
            if(found){
                cout<<(matching.matchedPieceID<secondMatching.matchedPieceID?matching.matchedPieceID:secondMatching.matchedPieceID)+1<<" "
                <<(matching.matchedPieceID>secondMatching.matchedPieceID?matching.matchedPieceID:secondMatching.matchedPieceID)+1<<"\n";
                return 0;
            }
        }catch(NoMatchFound &e){
            failedMatchCount[matching.matchedPieceID]++;
            if(failedMatchCount[matching.matchedPieceID]==10){
                failedPieces.insert({matching.matchedPieceID});
            }
        }
    }
}
