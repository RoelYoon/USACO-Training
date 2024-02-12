/*
ID: roelyoon
TASK: dualpal
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> decToVec(int num, int &base){
    vector<int> vec(32);
    int p = 31; 
    int i = 0;
    while(num>0){
        while(pow(base,p)>num){
            i++;
            p--;
        }
        while(num>=pow(base,p)){
            vec[i]++;
            num-=pow(base,p);
        }
    }
    return vec; 
}
string toString(vector<int> &num){
    string s = "";
    int ind; 
    for(int i = 0; i < num.size(); i++){
        if(num[i]!=0){
            ind = i; 
            break;
        }
    }
    for(int i = ind; i < num.size(); i++)
        s+=to_string(num[i]);
    return s; 
}
bool isPalindrome(vector<int> &num){
    string s = toString(num); 
    for(int i = 0; i < s.size()/2; i++){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dualpal.in","r",stdin);
    //freopen("dualpal.out","w",stdout);
    int n, s; cin>>n>>s; 
    vector<int> answers; 
    while(n>0){
        s++; 
        int count = 0;
        for(int b = 2; b <= 10; b++){
            vector<int> vec = decToVec(s,b);
            if(isPalindrome(vec)){
                count++;
                if(count==2){
                    answers.push_back(s);
                    n--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < answers.size(); i++){
        cout<<answers[i]<<"\n";
    }
}