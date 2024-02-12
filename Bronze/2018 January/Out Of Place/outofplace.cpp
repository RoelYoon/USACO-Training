#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout); 
    int n; cin>>n; 
    int line[105]; 
    int bessie;
    int prev = 1e7; 
    for(int i = 0; i < n; i++)
        cin>>line[i]; 
    for(int i = 0; i < n; i++){
        if(prev>line[i]){
            if(i==1 || i>1 && line[i]>line[i-2]){
                bessie=i-1; 
            }
            else{
                bessie=i;
            }
        }
        prev=line[i];
    }
    int count = 0; 
    int bHeight = line[bessie];
    //true-upward false-downward
    if(bessie!=n-1 && line[bessie]>line[bessie+1]){
        for(int i = bessie+1; i < n; i++){
            if(bHeight<=line[i]){break;}
            int j = i+1; 
            while(j<n && line[j]==line[i]){
                i++; 
                j++; 
            }
            count++; 
        }
    }else{
        for(int i = bessie-1; i >= 0; i--){
            if(bHeight>=line[i]){break;}
            int j = i-1; 
            while(j>=0 && line[j]==line[i]){
                i--; 
                j--; 
            }
            count++; 
        }
    }
    cout<<count<<"\n"; 
}