/*
ID: roelyoon
TASK: cow college
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reach(long long i, long long k, string &line, char breed){
    int count1=0,count2=0;
    string v2=line;
    //string v2=line;
    /*
    for(int ind=i-1; ind>=i-(2*k); ind--){
        if(ind>=0){
            if(line[ind]==breed){
                v1[ind]='N';
                count1++;
            }
        }
    }
    */
    for(int ind=i+1; ind<=i+(2*k); ind++){
        if(ind<=line.length()-1){
            if(line[ind]==breed){
                v2[ind]='N';
                count2++;
            }
        }
    }
    line=v2;
    if(line[i]==breed){
        line[i]='N';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        long long n,k;
        string line; 
        cin>>n>>k>>line;
        string lineCopy = line;
        char ans[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(ans[i]!='G'&&ans[i]!='H'){
                ans[i]='.';
            }
            if(lineCopy[i]=='G'){
                reach(i,k,lineCopy,'G');
                int point = i+k;
                if(point>n-1){
                    point = n-1;
                }
                while(ans[point]=='G'||ans[point]=='H'){
                    point--;
                }
                ans[point]='G';
                count++;
            }else if(lineCopy[i]=='H'){
                reach(i,k,lineCopy,'H');
                int point = i+k;
                if(point>n-1){
                    point = n-1;
                }
                while(ans[point]=='G'||ans[point]=='H'){
                    point--;
                }
                ans[point]='H';
                count++;
            }
        }
        cout << count << "\n";
        for(int i =0; i<n;i++){
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0; 
}
