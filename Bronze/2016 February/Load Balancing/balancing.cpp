#include <iostream>
using namespace std;
int n, b;
struct Cow{
    int x;
    int y;
    Cow(){}
    Cow(int x, int y):x(x),y(y){}
    int quadrant(int xLine, int yLine){
        if(x>xLine && y>yLine){return 0;}
        else if(x>xLine && y<yLine){return 1;}
        else if(x<xLine && y<yLine){return 2;}
        else{return 3;}
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    cin>>n>>b;
    Cow cows[105];
    for(int i = 0; i < n; i++){
        cin>>cows[i].x>>cows[i].y;
    }
    int ans = 105;
    for(int i = 0; i < n; i++){
        int xLine = cows[i].x+1;
        for(int j = 0; j < n; j++){
            int yLine = cows[j].y+1;
            int population[4]{0,0,0,0};
            int maxPop = 0;
            for(int k = 0; k < n; k++){
                int quad = cows[k].quadrant(xLine,yLine);
                population[quad]++;
                maxPop = max(maxPop,population[quad]);
            }
            ans=min(ans,maxPop);
        }
    }
    cout<<ans<<"\n";
}