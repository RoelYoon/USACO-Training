#include <iostream>
#include <vector>
using namespace std;
struct WordPair{
    string word1;
    string word2;
    int letterCount[26]{};
    WordPair(){
        cin>>word1>>word2;
        int word1Letters[26]{};
        int word2Letters[26]{};
        for(int i = 0; i<word1.size(); i++)
            word1Letters[word1[i]-97]++;
        for(int i = 0; i<word2.size(); i++)
            word2Letters[word2[i]-97]++;
        for(int i = 0; i < 26; i++)
            letterCount[i]=max(word1Letters[i],word2Letters[i]);
    }
};
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    cin>>n;
    vector<WordPair> wordPairs(n);
    int allLetterCount[26]{};
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < n; j++){
            allLetterCount[i]+=wordPairs[j].letterCount[i];
        }
        cout<<allLetterCount[i]<<"\n";
    }
}
