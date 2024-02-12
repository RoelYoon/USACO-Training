/*
ID: roelyoon
TASK: name
LANG: C++    
*/       
#include <iostream>
#include <array>
using namespace std;
bool match(int a, int b, int c, array<int, 7> ints){
    int hints[4] = {a+b,b+c,c+a,a+b+c};
    for(int i = 0; i < 7; i++){
        if(ints[i]==a){
            ints[i]=0;
            a=-1;
        }else if(ints[i]==b){
            ints[i]=0;
            b=-1;
        }else if(ints[i]==c){
            ints[i]=0;
            c=-1;
        }
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            if(hints[j]==ints[i]){
                ints[i]=0;
                hints[j]=-1;
                break;
            }
        }
    }
    bool found = true; 
    for(int i = 0; i < 7; i++){
        if(ints[i]!=0){found=false; break;}
    }
    return found;
}
void printAns(int a,int b,int c){
    if(a<=b&&b<=c){cout<<a<<" "<<b<<" "<<c;}
    else if(a<=c&&c<=b){cout<<a<<" "<<c<<" "<<b;}
    else if(b<=a&&a<=c){cout<<b<<" "<<a<<" "<<c;}
    else if(b<=c&&c<=a){cout<<b<<" "<<c<<" "<<a;}
    else if(c<=a&&a<=b){cout<<c<<" "<<a<<" "<<b;}
    else if(c<=b&&b<=a){cout<<c<<" "<<b<<" "<<a;}
}
int main(){
    array<int,7> ints;
    for(int i = 0; i < 7; i++){
        cin>>ints[i];
    }
    for(int i = 0; i < 7; i++){
        int a = ints[i];
        for(int j = 0; j < 7; j++){
            if(i!=j){
                int b = ints[j];
                for(int k = 0; k < 7; k++){
                    if(k!=i && k!=j){
                        int c = ints[k];
                        if(match(a,b,c,ints)){printAns(a,b,c); return 0;}
                    }
                }
            }
        }
    }
}
// 11 9 4 2 7 9 2
/*
11 7 9 9 2 4 2
*/