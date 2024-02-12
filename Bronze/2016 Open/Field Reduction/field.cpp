#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct Coord{
    int x; 
    int y;
    int id;
    Coord(){}
    Coord(int x, int y):x(x),y(y){}
};
long long area(vector<Coord> &edgePoints,int banned){
    int rightMost=-1;
    int leftMost=50000;
    int highest=-1;
    int lowest=50000;
    for(int i  = 0; i < edgePoints.size(); i++){
        if(edgePoints[i].id==banned){continue;}
        rightMost = max(rightMost,edgePoints[i].x);
        leftMost = min(leftMost,edgePoints[i].x);
        highest = max(highest,edgePoints[i].y);
        lowest = min(lowest,edgePoints[i].y);
    }
    return (long long)(rightMost-leftMost)*(long long)(highest-lowest);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("reduce.in","r",stdin);
    freopen("reduce.out","w",stdout);
    cin>>n;
    vector<Coord> coords(n);
    for(int i = 0; i < n; i++){
        cin>>coords[i].x>>coords[i].y;
        coords[i].id=i;
    }
    vector<Coord> maxCows;
    vector<int> bannedID;
    sort(coords.begin(),coords.end(),[](const Coord &a, const Coord &b){return a.x<b.x;});
    maxCows.push_back(coords[n-1]);
    bannedID.push_back(coords[n-1].id);
    maxCows.push_back(coords[n-2]);
    maxCows.push_back(coords[0]);
    bannedID.push_back(coords[0].id);
    maxCows.push_back(coords[1]);
    sort(coords.begin(),coords.end(),[](const Coord &a, const Coord &b){return a.y<b.y;});
    maxCows.push_back(coords[n-1]);
    bannedID.push_back(coords[n-1].id);
    maxCows.push_back(coords[n-2]);
    maxCows.push_back(coords[0]);
    bannedID.push_back(coords[0].id);
    maxCows.push_back(coords[1]);
    long long minArea = 1000000000000;
    minArea = min(minArea,min(area(maxCows,bannedID[0]),min(area(maxCows,bannedID[1]),min(area(maxCows,bannedID[2]),area(maxCows,bannedID[3])))));
    cout<<minArea<<"\n";
}
