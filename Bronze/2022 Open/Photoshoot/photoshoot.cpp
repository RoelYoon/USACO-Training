//Unfinished
#include <iostream>
using namespace std;
void reverse(string& s, int k){
    for(int i = 0; i <= k/2; i++){
        char temp = s[i];
        s[i] = s[k-i]; 
        s[k-i] = temp; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    int count = 0; 
    for(int i = n-1; i >= 0; i-=2){
        int score = 0; 
        for(int j = 1; j <= i; j+=2){
            if(s[j]=='G' && s[i-j]=='H'){score--;}
            else if(s[j]=='H' && s[i-j]=='G'){score++;}
        }
        if(score>0){
            reverse(s,i);
            count++;
        }
    }
    cout<<count<<"\n";
}
