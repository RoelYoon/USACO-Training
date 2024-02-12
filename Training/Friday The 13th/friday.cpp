/*
ID: roelyoon
TASK: friday
LANG: C++                 
*/
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("friday.in","r",stdin);
    //freopen("friday.out","w",stdout);
    int n;
    cin>>n;
    int dayCount[7]={};
    int weekDay=0;
    for(int year = 1900; year<1900+n; year++){
        bool isLeap = false;
        if(year%100==0 && year%400==0){
            isLeap=true;
        }else if(year%100!=0 && year%4==0){
            isLeap=true;
        }
        for(int month = 1; month<=12; month++){
            for(int day = 1; day<=31; day++){
                if(day==31){
                    if(month==9||month==4||month==6||month==11){
                        break;
                    }
                }else if(day==29 && !isLeap || day==30 && isLeap){
                    if(month==2){
                        break;
                    }
                }
                if(day==13){
                    dayCount[weekDay]++;
                }
                weekDay=(weekDay+1)%7;
            }
        }
    }  
    cout<<dayCount[5]<<" "<<dayCount[6]<<" "<<dayCount[0]<<" "<<dayCount[1]<<" "<<dayCount[2]<<" "<<dayCount[3]<<" "<<dayCount[4]<<"\n";
}