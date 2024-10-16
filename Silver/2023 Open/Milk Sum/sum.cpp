#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n;
    vector<ll> milk(n);
    vector<ll> smilk(n);
    vector<ll> ps(n);
    for(int i = 0; i < n; ++i){
        cin>>milk[i];
        smilk[i]=milk[i];
    }
    sort(smilk.begin(),smilk.end());
    ps[0]=smilk[0];
    ll mxP=smilk[0];
    for(int i = 1; i < n; ++i){
        ps[i]=smilk[i]+ps[i-1];
        mxP+=(ll)(smilk[i]*(ll)(i+1));
    }
    cin>>q;
    for(int i = 0; i < q; ++i){
        int p; ll v; cin>>p>>v; --p;
        int curPos = lower_bound(smilk.begin(),smilk.end(),milk[p])-smilk.begin();
        int updPos = upper_bound(smilk.begin(),smilk.end(),v)-smilk.begin();
        if(v>=milk[p]){
            //mxP increase; updPos>curPos
            --updPos;
            if(curPos==updPos){
                cout<<(ll)((ll)mxP-(ll)(milk[p]*(ll)(curPos+1))+(ll)(v*(ll)(updPos+1)))<<"\n";
                continue;
            }
            cout<<(ll)((ll)mxP-(ll)(ps[updPos]-(curPos<0?0:ps[curPos]))-(ll)(milk[p]*(ll)(curPos+1))+(ll)(v*(ll)(updPos+1)))<<"\n";
        }else if(v<milk[p]){
            //mxP decrease; updPos<curPos
            if(curPos==updPos){
                cout<<(ll)((ll)mxP-(ll)(milk[p]*(ll)(curPos+1))+(ll)(v*(ll)(updPos+1)))<<"\n";
                continue;
            }
            cout<<(ll)((ll)mxP+(ll)(ps[curPos-1]-(updPos-1<0?0:ps[updPos-1]))-(ll)(milk[p]*(ll)(curPos+1))+(ll)(v*(ll)(updPos+1)))<<"\n";
        }
    }
}
/*
5
10 10 4 10 10
2
3 100
1 100

5 
0 0 0 5 0
3
2 100000000
4 5
1 1

2
0 1
1
1 2

100
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1
1 100000000
*/