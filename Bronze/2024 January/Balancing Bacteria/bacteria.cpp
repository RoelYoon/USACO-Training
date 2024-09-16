#include <iostream>
#include <vector>
#define ll long long
#define MAX 200005
using namespace std;
class SegmentTree{
    #define LC(i) (2*(i)+1)
    #define RC(i) (2*(i)+2)
    int n;
    vector<ll> st;
    vector<bool> lazyFlag;
    vector<ll> lazyUpdate;
    inline bool outBounds(int L, int R, int QL, int QR){
        return R<QL || L>QR;
    }
    inline bool inBounds(int L, int R, int QL, int QR){
        return L>=QL && R<=QR;
    }
    void propagate(int p, int L, int R){
        if(lazyFlag[p]){
            st[p] += (R-L+1)*lazyUpdate[p];
            if(L!=R){
                lazyFlag[LC(p)]=lazyFlag[RC(p)]=1;
                lazyUpdate[LC(p)]+=lazyUpdate[p];
                lazyUpdate[RC(p)]+=lazyUpdate[p];
            }
            lazyUpdate[p]=0;
            lazyFlag[p]=0;
        }
    }
    ll query(int p, int L, int R, int QL, int QR){
        propagate(p,L,R);
        if(outBounds(L,R,QL,QR)){
            return 0;
        }
        if(inBounds(L,R,QL,QR)){
            return st[p];
        }
        int mid = (L+R)/2;
        return query(LC(p),L,mid,QL,QR) + query(RC(p),mid+1,R,QL,QR);
    }
    void update(int p, int L, int R, int QL, int QR, ll u){
        propagate(p,L,R);
        if(outBounds(L,R,QL,QR)){
            return;
        }
        if(inBounds(L,R,QL,QR)){
            lazyFlag[p]=1;
            lazyUpdate[p]+=u;
            propagate(p,L,R);
            return;
        }
        int mid = (L+R)/2;
        update(LC(p),L,mid,QL,QR,u);
        update(RC(p),mid+1,R,QL,QR,u);
        st[p] = st[LC(p)] + st[RC(p)];
    }
    public:
    SegmentTree(int n, ll data[MAX]):n(n),st(4*n),lazyFlag(4*n),lazyUpdate(4*n){build(0,0,n-1,data);}
    void build(int p, int L, int R, ll data[MAX]){
        if(L==R){
            st[p]=data[L];
            return;
        }
        int mid = (L+R)/2;
        build(LC(p),L,mid,data);
        build(RC(p),mid+1,R,data);
        st[p]=st[LC(p)]+st[RC(p)];
    }
    ll query(int p){
        return query(0,0,n-1,p,p);
    }
    void update(int L, int R, ll u){
        update(0,0,n-1,L,R,u);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    ll a[MAX]{};
    ll ls[MAX]{};
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    ls[0]=a[0];
    for(int i = 1; i < n; ++i)
        ls[i]=a[i]-a[i-1];
    SegmentTree st(n,ls);
    ll count = 0;
    for(int i = 0; i < n; ++i){
        ll q = st.query(i);
        count+=(q<0 ? q*-1 : q);
        st.update(i,n-1,q*-1);
    }
    cout<<count<<"\n";
}