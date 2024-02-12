#include <iostream>
#include <vector>
using namespace std;
int n;
string line;
int minMaxNights=1000000000;
struct Blob{
    int size;
    bool edge;
    bool end; 
    int maxNights;
    Blob(int s,bool e,bool ed):size(s),edge(e),end(ed){
        maxNights=0;
        if(!edge){
            maxNights+=(s%2==0?(s-2)/2:(s-1)/2);
        }else{
            maxNights=s-1;
        }
        if(maxNights<minMaxNights){
            minMaxNights=maxNights;
        }
    }
    int rollBackCount(int nights,int sizeSeg, bool isEdge,bool hasSplit){
        if(isEdge && size%2==1 && hasSplit){sizeSeg++;}
        if(isEdge){
            if(nights>=sizeSeg/2){
                sizeSeg=1;
            }else if(sizeSeg-nights*2>0){
                sizeSeg-=(nights*2);
            }else{
                sizeSeg-=nights;
            }
        }else{
            sizeSeg-=2*nights;
        }
        return sizeSeg;
    }
    int rollBack(int nights){
        int sizeCount=0;
        int sizeCopy=size;
        int segCount=1;
        while((sizeCopy/2-(nights*2))>0){
            segCount*=2;
            sizeCopy/=2;
        }
        for(int i = 0; i < segCount; i++){
            sizeCount+=rollBackCount(nights,size/segCount,edge?(end?(i==segCount-1?true:false):(edge&&i==0?true:false)):i==0?true:false,segCount!=1);
        }
        return sizeCount;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>line;
    vector<Blob> blobs;
    //find blobs
    int cnt=0;
    bool isBlob=false;
    bool edge=line[0]=='1';
    for(int i = 0; i < n; i++){
        if(line[i]=='1'){
            cnt++;
            isBlob=true;
            if(i==n-1){
                blobs.push_back(Blob(cnt,true,true));
            }
        }else if(isBlob){
            if(edge){
                blobs.push_back(Blob(cnt,true,false));
                edge=false;
            }else{
                blobs.push_back(Blob(cnt,false,false));
            }
            cnt=0;
            isBlob=false;
        }
    }
    int minInfectionCnt=0;
    for(int i = 0; i < blobs.size(); i++){
        minInfectionCnt+= blobs[i].rollBack(minMaxNights);
    }
    cout<<minInfectionCnt<<"\n";
}
