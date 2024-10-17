#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    string s("",n);
    for(int i = 0; i < n; ++i){
        cin>>s[i];
    }
    string ans="";
    int i=0,j=n-1;
    while(i<=j){
        if(s[i]==s[j]){
            //recurse
            int ti=i,tj=j;
            while(ti<tj && s[ti]==s[tj]){
                ++ti; --tj;
            }
            if(s[ti]<s[tj]){
                ans+=s[i];
                ++i;
            }else{
                ans+=s[j];
                --j;
            }
        }else{
            if(s[i]<s[j]){
                ans+=s[i];
                ++i;
            }else{
                ans+=s[j];
                --j;
            }
        }
    }
    for(int i = 0; i<n; ++i){
        cout<<ans[i];
        if((i+1)%80==0) cout<<"\n";
    }
}
/*
6
A
A
B
A
A
A
*/