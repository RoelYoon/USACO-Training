#include <iostream>
#include <string>
#define MAX 100005
using namespace std;
int n,k;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>k>>s;
        bool covered[MAX] = {};
        int patchCount = 0;
        string patch = ""; for(int i = 0; i < n; i++){patch+=".";}
        for(int i = 0; i < n;i++){
            if(!covered[i]){
                int a = k;
                if(i+k<n && patch[i+k]=='.'){patch[i+k]=s[i];}
                else{
                    while(!(i+a<n && patch[i+a]=='.'))
                        a--;
                    patch[i+a]=s[i];
                }
                for(int j = i; j <= ((i+a+k)<n?(i+a+k):n-1); j++)
                    if(s[j]==s[i])
                        covered[j]=true;
                patchCount++;
            }
        }
        cout<<patchCount<<"\n"<<patch<<"\n";
    }
}