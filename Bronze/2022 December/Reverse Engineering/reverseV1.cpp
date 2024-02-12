#include <iostream>
#include <vector>
#include <bitset> 
#include <cstdio>
#include <fstream>
using namespace std;
int main(){
    ifstream file("inp.txt");
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<bitset<100>> falseOutputs, trueOutputs;   
        for(int i = 0; i < m; i++){
            string bitInput; cin>>bitInput; 
            bool output; cin>>output;
            if(output){trueOutputs.push_back(bitset<100>(bitInput));}
            else{falseOutputs.push_back(bitset<100>(bitInput));}
        }
        bool isOkay = true; 
        for(int i = 0; i < falseOutputs.size(); i++){
            for(int j = 0; j < trueOutputs.size(); j++){
                bitset<100> test = falseOutputs[i] & trueOutputs[j];
                if(!test.any()){break;}
                if(j==trueOutputs.size()-1){isOkay=false;}
            }
            for(int j = 0; j < trueOutputs.size(); j++){
                bitset<100> falseOutput(falseOutputs[i]);
                bitset<100> trueOutput(trueOutputs[j]);
                falseOutput.flip(); trueOutput.flip();
                bitset<100> test=falseOutput&trueOutput;
                if(test.count()-(100-n)==0){break;}
                if(j==trueOutputs.size()-1){isOkay=false;}
            }
        }
        cout<<(isOkay?"OK":"LIE")<<"\n"; 
    }
    return 0;
}