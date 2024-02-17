#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            double avg = 0;
            for(int k = i; k <= j; k++){
                avg+=p[k];
            }
            avg/=(j-i)+1;
            for(int k = i; k <= j; k++){
                if(abs((double)p[k]-avg)<=1e-9){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<"\n";
}