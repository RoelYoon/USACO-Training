/*
ID: roelyoon
TASK: name
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;
struct logSum{
    int sum;
    int cnt; 
    int originIndex;
    public:
        logSum(int s, int c, int o){
            sum=s;
            cnt = c;
            originIndex=o;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0; 
    cin>>t; 
    for(int testCase = 0; testCase < t; testCase++){
        int n;
        cin>>n;
        vector<int> log;
        unordered_map<int, logSum> sums; 
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            int temp; 
            cin>>temp;
            log.push_back(temp);
        }
        while(true){
            if(log.size()==1 || sums.find(log[0]+log[1])!=sums.end() && sums.at(log[0]+log[1]).cnt == log.size()){
                break;
            }
            unordered_map<int, int> logCounts;
            for(int i = 0; i < log.size(); i++){
                int val = log[i];
                if(logCounts.find(val)!=logCounts.end()){
                    logCounts.at(val)+=1;
                }else{
                    logCounts.insert({val,1});
                }
            }
            int maxCnt=0;
            int origin=0;
            bool matched=false;
            int min=1000000;
            int backUpOrigin=0;
            for(int i = 0; i < log.size()-1; i++){
                int sum=log[i]+log[i+1];
                if(sums.find(sum)!=sums.end()){
                    sums.at(sum).cnt++;
                    if(logCounts.find(sum)!=logCounts.end()&&logCounts.at(sum)>maxCnt){
                        maxCnt=logCounts.at(sum);
                        origin=sums.at(sum).originIndex;
                        matched=true;
                    }
                }else{
                    logSum temp(sum,0,i);
                    sums.insert({sum,temp});
                    if(logCounts.find(sum)!=logCounts.end()&&logCounts.at(sum)>=maxCnt){
                        maxCnt=logCounts.at(sum);
                        origin=sums.at(sum).originIndex;
                        if(sum<min){
                            min=sum;
                            backUpOrigin=origin;
                        }
                    }
                }
            }
            if(testCase==0){
                cout<<"\nSum: "<<log[origin]+log[origin+1]<<",Origin: "<< origin<<"\n";
                //if(logCounts.find(3)!=logCounts.end()){cout<<logCounts.at(3);}
            }
            int temp = log[origin]+log[origin+1];
            log.insert(log.begin()+origin, temp);
            log.erase(log.begin()+origin+1);
            log.erase(log.begin()+origin+1);
            sums.clear();
            cnt++;
        }
        cout<<cnt;
    }
    return 0; 
}