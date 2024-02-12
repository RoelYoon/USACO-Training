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
    int width;
    int height;
    Rectangle(){
        width = tr.x-bl.x;
        height = tr.y-bl.y;
        area = width*height;
    }
};
bool isBetween(int c, int a, int b){
    return a<c && c<b;
}
int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    Rectangle lawnmower;
    Rectangle feed;
    int sWidth = min(lawnmower.tr.x,feed.tr.x) - max(lawnmower.bl.x,feed.bl.x);
    int sHeight = min(lawnmower.tr.y,feed.tr.y) - max(lawnmower.bl.y,feed.bl.y);
    cout<<lawnmower.area-((sWidth==lawnmower.width || sHeight==lawnmower.height)&&(sWidth>=0 && sHeight>=0)
    &&(!(isBetween(feed.tr.x,lawnmower.bl.x,lawnmower.tr.x) && isBetween(feed.bl.x,lawnmower.bl.x,lawnmower.tr.x)))
    &&(!(isBetween(feed.tr.y,lawnmower.bl.y,lawnmower.tr.y) && isBetween(feed.bl.y,lawnmower.bl.y,lawnmower.tr.y)))?(sWidth*sHeight):0)<<"\n";
}