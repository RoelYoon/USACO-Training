#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("6.in","r",stdin);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<string> inputs(m);
        vector<char> outputs(m); 
        vector<bool> ignore(m,false);
        for(int i = 0; i < m; i++){
            cin>>inputs[i]>>outputs[i];
        }
        const char bit[2]{'0','1'}; 
        for(int i = 0; i < n; i++){
            bool decidingVar = true;
            bool set = 0; 
            char setBit;
            for(int j = 0; j < 2; j++){
                bool set = 0; 
                char setBit;
                decidingVar = true;
                for(int k = 0; k < m; k++){
                    if(ignore[k]){continue;}
                    if(inputs[k][i] == bit[j]){
                        if(!set){
                            set=true;
                            setBit = outputs[k];
                        }else{
                            if(outputs[k]!=setBit){
                                decidingVar=false;
                                break;
                            }
                        }
                    }
                }
                if(decidingVar && set){
                    for(int k = 0; k < m; k++){
                        if(inputs[k][i]==bit[j]){
                            ignore[k]=true;
                        }
                    }
                }
            }
        }
        bool possible = true;
        for(int i = 0; i < m; i++){
            if(!ignore[i]){
                possible=false;
            }
        }
        cout<<(possible?"OK":"LIE")<<"\n";
    }
}