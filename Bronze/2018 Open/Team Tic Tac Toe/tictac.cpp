#include <iostream>
using namespace std;
char board[3][3];
bool point(bool rowMajor, bool diagonal, bool reverse, char first, char second){
    int points = diagonal?1:3;
    bool firstUsed = false;
    bool secondUsed = false;
    for(int r = reverse?2:0; reverse? r>=0 : r < 3; r+=reverse?-1:1){
        bool firstShown = false;
        bool secondShown = false;
        bool pointEarned = true;
        for(int c = reverse?2:0; reverse?c>=0:c < 3; c+=reverse?-1:1){
            if(board[rowMajor?r:c][rowMajor?c:r]==first){firstShown=true;}
            if(board[rowMajor?r:c][rowMajor?c:r]==second){secondShown=true;}
            if(board[rowMajor?r:c][rowMajor?c:r]!=first && board[rowMajor?r:c][rowMajor?c:r]!=second){
                points--;
                pointEarned=false;
                if(diagonal){return 0;}
                break;
            }
            r+=diagonal?reverse?-1:1:0;
        }
        if(pointEarned){
            firstUsed=firstShown;
            secondUsed=secondShown;
        }
    }
    return points>0 && (second=='x'?1:firstUsed && secondUsed);
}
int main(){
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            cin>>board[r][c];
        }
    }
    int individualCount=0;
    int teamCount=0;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool counted[26][26]{};
    for(int i = 0; i < 26; i++){
        individualCount += point(1,0,0,alphabet[i],'x')
                        || point(0,0,0,alphabet[i],'x')
                        || point(1,1,0,alphabet[i],'x')
                        || point(1,1,1,alphabet[i],'x');
        for(int j = 0; j < 26; j++){
            if(i==j || counted[i][j]){continue;}
            counted[i][j]=true;
            counted[j][i]=true;
            teamCount += point(1,0,0,alphabet[i],alphabet[j])
                        || point(0,0,0,alphabet[i],alphabet[j])
                        || point(1,1,0,alphabet[i],alphabet[j])
                        || point(1,1,1,alphabet[i],alphabet[j]);
        }
    }
    cout<<individualCount<<"\n"<<teamCount<<"\n";
}