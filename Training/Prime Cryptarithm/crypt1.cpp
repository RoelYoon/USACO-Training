/*
ID: roelyoon
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <vector> 
#include <unordered_set>
using namespace std;
void generateOperands(vector<int> &numbers, vector<string> &triples, vector<string> &doubles, string num, int depth){
    if(depth==3){
        triples.push_back(num);
        return;
    }
    if(depth==2){
        doubles.push_back(num);
    }
    for(int n : numbers)
        generateOperands(numbers,triples,doubles,num+to_string(n),depth+1);
}
bool checkValid(unordered_set<int> &set, int n){
    string num = to_string(n);
    for(int i = 0; i < num.size(); i++)
        if(set.find((int)num[i]-48)==set.end()){return false;}
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("crypt1.in","r",stdin);
    //freopen("crypt1.out","w",stdout);
    int n; cin>>n;
    vector<int> numbers(n);
    unordered_set<int> set;
    for(int i = 0; i<n; i++){
        cin>>numbers[i];
        set.insert({numbers[i]});
    }
    vector<string> triples;
    vector<string> doubles;
    generateOperands(numbers,triples,doubles,"",0);
    int validCount = 0;
    for(string op1 : triples){
        for(string op2 : doubles){
            int p1 = stoi(op1)*((int)op2[1]-48);
            int p2 = stoi(op1)*((int)op2[0]-48)*10;
            if(to_string(p1).size()==3 && to_string(p2/10).size()==3 && checkValid(set,p1) && checkValid(set,p2/10) && p1+p2 == stoi(op1)*stoi(op2) && checkValid(set,p1+p2))
                validCount++;
        }
    }
    cout<<validCount<<"\n";
}