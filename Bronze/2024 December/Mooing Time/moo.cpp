#include <iostream>
#include <vector>
#include <string>
using namespace std;
int find(string &moo, string &s){
    int cnt = 0;
    bool passUsed=0;
    for(int i = 0; i < s.size()-2; ++i){
        int mismatch=0;
        int mi = -1;
        for(int j = 0; j < 3; ++j){
            if(moo[j]!=s[i+j]){
                ++mismatch;
                mi=j;
            }
        }
        if(mi!=-1 && !passUsed){
            if(mismatch==1){
                bool disrupts=s.substr(i+mi,3)==moo;
                if(!disrupts){
                    ++cnt;
                    passUsed=1;
                    i+=2;
                }
            }
        }else if(mi==-1){
            ++cnt;
            i+=2;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,f; cin>>n>>f;
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    string s; cin>>s;
    string moo = "";
    vector<string> ans; ans.reserve(100000);
    for(int i = 0; i < 26; ++i){
        moo.push_back(alphabet[i]);
        for(int j = 0; j < 26; ++j){
            if(alphabet[i]==alphabet[j]) continue;
            moo.push_back(alphabet[j]);
            moo.push_back(alphabet[j]);
            if(find(moo,s)>=f)
                ans.push_back(moo);
            moo.pop_back();
            moo.pop_back();
        }
        moo.pop_back();
    }
    cout<<ans.size()<<"\n";
    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i]<<"\n";
    }
}