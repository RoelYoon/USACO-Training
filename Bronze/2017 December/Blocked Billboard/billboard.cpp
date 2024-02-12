#include <iostream>
using namespace std;
struct Point{
    int x;
    int y;
    Point(){cin>>x>>y;}
};
struct Rectangle{
    Point bl;
    Point tr;
    int area;
    Rectangle(){
        area=(tr.x-bl.x)*(tr.y-bl.y);
    }
};
int intersectionArea(Rectangle &a, Rectangle &b){
    int width = (min(a.tr.x,b.tr.x)-max(a.bl.x,b.bl.x));
    int height = (min(a.tr.y,b.tr.y)-max(a.bl.y,b.bl.y));
    return (width<0 || height<0 ? -1 : width*height);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    Rectangle billboard1, billboard2, truck;
    int full = billboard1.area + billboard2.area;
    int block1 = intersectionArea(billboard1,truck);
    int block2 = intersectionArea(billboard2,truck);
    cout<<full-(block1>0?block1:0)-(block2>0?block2:0)<<"\n";
}
