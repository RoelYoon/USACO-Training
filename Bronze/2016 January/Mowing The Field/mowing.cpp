#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
struct Position{
    int x; 
    int y;
    Position(int x, int y):x(x),y(y){}
    bool operator==(const Position &other) const{
        return x==other.x && y==other.y;
    }
    struct Hash{
        size_t operator()(const Position &pos) const{
            return hash<int>()(pos.x) ^ hash<int>()(pos.y);
        }
    };
};
struct Move{
    int time;
    int xDir;
    int yDir;
    Move(){}
    Move(int t, int x, int y):time(t),xDir(x),yDir(y){}
    void setDir(char dir){
        if(dir=='N'){xDir=0;yDir=1;}
        else if(dir=='E'){xDir=1;yDir=0;}
        else if(dir=='S'){xDir=0;yDir=-1;}
        else if(dir=='W'){xDir=-1;yDir=0;}
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    cin>>n;
    Move moves[105];
    for(int i = 0; i < n; i++){
        char dir; cin>>dir>>moves[i].time;
        moves[i].setDir(dir);
    }
    unordered_map<Position,int,Position::Hash> map;
    Position pos(0,0);
    int t = 0;
    int maxT = 1000000000;
    bool met = false; 
    for(int m = 0; m < n; m++){
        Move move = moves[m];
        for(int i = 0; i < move.time; i++){
            if(map.find(pos)!=map.end()){
                met=true;
                maxT = min(maxT,t-map.find(pos)->second);
            }
            map[pos] = t;
            pos.x+=move.yDir;
            pos.y+=move.xDir;
            t++;
        }
    }
    cout<<(met?maxT:-1)<<"\n";
}

