#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class KMP{
    string &P;
    int m;
    vector<int> reset;
    public:
    KMP(string &s):P(s),m(P.size()),reset(m){
        int i=0,j=-1; reset[i]=j;
        while(i<m){
            while(j>=0 && P[i]!=P[j])
                j=reset[j];
            ++i,++j;
            reset[i]=j;
        }
    }
    int find(string &T){
        int cnt = 0;
        int i=0,j=0;
        while(i<T.size()){
            while(j>=0 && P[j]!=T[i])
                j=reset[j];
            ++i,++j;
            if(j==m){
                ++cnt;
                j=reset[j];
            }
        }
        return cnt;
    }
};
bool isMoo(string &s){
    return s[0]!=s[1]&&s[0]!=s[2]&&s[1]==s[2];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,f; cin>>n>>f;
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    string s; cin>>s;
    set<string> found;
    for(int i = 0; i < n-2; ++i){
        string moo=s.substr(i,3);
        string copyMoo = moo;
        for(int j = 0; j < 26; ++j){
            moo[0]=alphabet[j];
            s[i]=alphabet[j];
            if(!isMoo(moo) || found.find(moo)!=found.end()) continue;
            KMP kmp(moo);
            if(kmp.find(s)>=f)
                found.insert(moo);
        }
        moo[0]=copyMoo[0];
        s[i]=copyMoo[0];
        {
            moo[1]=moo[2];
            s[i+1]=moo[2];
            if(isMoo(moo) && found.find(moo)==found.end()){
                KMP kmp(moo);
                if(kmp.find(s)>=f)
                    found.insert(moo);
            }
            moo[1]=copyMoo[1];
            s[i+1]=copyMoo[1];
        }
        {
            moo[2]=moo[1];
            s[i+2]=moo[1];
            if(isMoo(moo) && found.find(moo)==found.end()){
                KMP kmp(moo);
                if(kmp.find(s)>=f)
                    found.insert(moo);
            }
            moo[2]=copyMoo[2];
            s[i+2]=copyMoo[2];
        }
    }
    cout<<found.size()<<"\n";
    for(set<string>::iterator it=found.begin(); it!=found.end(); ++it){
        cout<<*it<<"\n";
    }
}