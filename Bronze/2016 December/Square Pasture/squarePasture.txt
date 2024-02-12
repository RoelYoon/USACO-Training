#include <iostream>
using namespace std;
struct Point{
    int x;
    int y;
};
struct Pasture{
    Point lowLeftCorner;
    Point upRightCorner; 
};
bool isBetween(int &a, int &c, int &b){return a<=c && c<=b;}
bool isContained(Pasture &p1, Pasture &p2, bool x){return x ? isBetween(p2.lowLeftCorner.x, p1.lowLeftCorner.x, p2.upRightCorner.x) && isBetween(p2.lowLeftCorner.x, p1.upRightCorner.x, p2.upRightCorner.x) : isBetween(p2.lowLeftCorner.y, p1.lowLeftCorner.y, p2.upRightCorner.y) && isBetween(p2.lowLeftCorner.y, p1.upRightCorner.y, p2.upRightCorner.y);}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    Pasture p1,p2;
    cin>>p1.lowLeftCorner.x>>p1.lowLeftCorner.y>>p1.upRightCorner.x>>p1.upRightCorner.y>>p2.lowLeftCorner.x>>p2.lowLeftCorner.y>>p2.upRightCorner.x>>p2.upRightCorner.y; 
    int squareX,squareY;
    if(isContained(p1,p2,1)){squareX=abs(p2.upRightCorner.x - p2.lowLeftCorner.x);}
    else if(isContained(p2,p1,1)){squareX=abs(p1.upRightCorner.x - p1.lowLeftCorner.x);}
    else{squareX=p1.lowLeftCorner.x < p2.lowLeftCorner.x ? abs(p1.lowLeftCorner.x - p2.upRightCorner.x) : abs(p2.lowLeftCorner.x - p1.upRightCorner.x);}
    if(isContained(p1,p2,0)){squareY=abs(p2.upRightCorner.y - p2.lowLeftCorner.y);}
    else if(isContained(p2,p1,0)){squareY=abs(p1.upRightCorner.y - p1.lowLeftCorner.y);}
    else{squareY=p1.lowLeftCorner.y < p2.lowLeftCorner.y ? abs(p1.lowLeftCorner.y - p2.upRightCorner.y) : abs(p2.lowLeftCorner.y - p1.upRightCorner.y);}
    cout<<(squareX>squareY?squareX*squareX:squareY*squareY)<<"\n";
}