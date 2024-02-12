#include <iostream>
#include <unordered_set>
using namespace std;
struct Move{
    int xMoves;
    int yMoves;
    Move(int x, int y):xMoves(x),yMoves(y){}
    bool operator==(const Move& other) const {
        return xMoves==other.xMoves && yMoves==other.yMoves;
    }
    struct Hash{
        size_t operator()(const Move& move) const {
            return hash<int>()(move.xMoves) ^ hash<int>()(move.yMoves);
        }
    };
};
int x,y,m; 
int maxFill = 0;
unordered_set<Move,Move::Hash> moves;
void findMax(Move move, int mLevel){
    if(mLevel>m || moves.find(move)!=moves.end()){
        return;
    }
    maxFill=max(maxFill,mLevel);
    moves.insert({move});
    findMax(Move(move.xMoves+1,move.yMoves),mLevel+x);
    findMax(Move(move.xMoves,move.yMoves+1),mLevel+y);
}
int main(){
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    cin>>x>>y>>m;
    findMax(Move(0,0),0);
    cout<<maxFill<<"\n";
}