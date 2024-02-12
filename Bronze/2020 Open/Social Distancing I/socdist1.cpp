/*
ID: roelyoon
TASK: socdist1
LANG: C++                 
*/
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    //freopen("socdist1.in","r",stdin);
    //freopen("socdist1.out","w",stdout);
    int n,max1=0,max2=0,count=0;
    string stalls;
    bool f0e=true,one = true;
    int f0=false,e0=false,an=false;;
    cin >> n >> stalls;
    for(int i=0; i<n;i++){
        if(stalls[i]=='0'){
            count++;
            if(i==n-1){
                e0=count;
            }
            if(an){
                one=false;
            }
        }
        if(count>=max1 && stalls[i]=='1' || count>=max1&&i==n-1){
            max2=max1;
            max1=count;
            if(f0e){
                f0=count;
            }
        }else if(count>max2){
            max2=count;
        }
        if(stalls[i]=='1'){count=0; f0e=false; if(!an && i!=0){an=true;}}
    }
    int case1 = max2/2 + max2%2;
    int case2 = max1/3;
    if(max2==f0 && f0<=e0||max2==e0 && e0<=f0){
        if(max2 < max1/2 + max1%2){
            case1=max2; 
        }else{
            if(max1==f0||max1==e0){
                if(max1<max2){
                    case1=max1;
                }else{
                    case1=max2;
                }
            }else{
                case1=max1/2 + max1%2;
            }
        }
    }
    if((max1-2)%3==0){
        case2++;
    }
    if(max1==f0||max1==e0){
        case2=(max1-1)/2 + (max1-1)%2;
    }
    if(one && f0==e0){
        case2=n-1;
    }
    if(case1>case2&&!one){
        cout<<case1<<"\n";
    }
    else{
        cout<<case2<<"\n";
    }
    return 0;
}