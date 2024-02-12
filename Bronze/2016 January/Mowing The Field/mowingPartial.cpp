#include <iostream>
#include <vector>
using namespace std;
int n;
struct Position{
    int x; 
    int y;
    Position(int x, int y):x(x),y(y){}
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
    int map[1005][1005];
    for(int r = 0; r < 1005; r++)
        for(int c = 0; c < 1005; c++)
            map[r][c] = -1;
    Position pos(1005/2,1005/2);
    int t = 0;
    int maxT = 1000000000;
    bool met = false; 
    for(int m = 0; m < n; m++){
        Move move = moves[m];
        for(int i = 0; i < move.time; i++){
            if(map[pos.x][pos.y]!=-1){
                met=true;
                maxT = min(maxT,t-map[pos.x][pos.y]);
            }
            map[pos.x][pos.y] = t;
            pos.x+=move.yDir;
            pos.y+=move.xDir;
            t++;
        }
    }
    cout<<(met?maxT:-1)<<"\n";
}
