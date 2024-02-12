#include <iostream>
#include <vector>
using namespace std;
int n;
struct Turn{
    int a;
    int b;
    Turn(){cin>>a>>b;}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    cin>>n;
    vector<Turn> turns(n);
    int maxWins=0;
    for(int rock = 1; rock <= 3; rock++){
        for(int paper = 1; paper <= 3; paper++){
            if(paper==rock){continue;}
            for(int scis = 1; scis <= 3; scis++){
                if(scis==rock || scis==paper){continue;}
                int wins=0;
                for(int i = 0; i < n; i++){
                    if(turns[i].a==rock && turns[i].b==scis){
                        wins++;
                    }else if(turns[i].a==paper && turns[i].b==rock){
                        wins++;
                    }else if(turns[i].a==scis && turns[i].b==paper){
                        wins++;
                    }
                }
                maxWins=max(maxWins,wins);
            }
        }
    }
    cout<<maxWins<<"\n";
}