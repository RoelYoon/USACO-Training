#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> h(n);
        ll minH = 1000000000;
        for(int i = 0; i < n; i++){
            cin>>h[i];
            minH = min(minH,h[i]);
        }
        bool impossible = minH<0?true:false;
        bool newMin=true;
        ll minBags = 0;
        while(newMin && !impossible){
            newMin = false;
            for(int i = 0; i < n; i++){
                if(i==n-1 && h[i]!=minH){impossible=1;}
                else if(h[i]>minH){
                    ll d = h[i]-minH;
                    h[i]-=d;
                    h[i+1]-=d;
                    minBags+=d*2;
                    if(h[i+1] < minH){
                        newMin=true;
                        minH = h[i+1];
                    }
                    if(h[i+1]<0){impossible=1;}
                }
            }
        }
        cout<<(impossible?-1:minBags)<<"\n";
    }
}