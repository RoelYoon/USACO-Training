#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,L; 
    cin>>n>>L;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin>>c[i];
    }
    sort(c.begin(),c.end());
    vector<bool> cited(n,false);
    int h = 1;
    for(int i = n-1; i >= 0; i--){
        if(c[i]<h){
            if(L>0){
                int j=i;
                while(j<n && c[j]< h && L>0){
                    if(cited[j]){goto end;}
                    c[j]++;
                    cited[j]=true;
                    L--;
                    j++;
                }if(j>=n){j--;}
                if(c[i]<h || c[j]<h || c[n-1]<h){
                    break;
                }
            }else{
                break;
            }
        }
        h++;
    }
    end: 
    cout<<h-1<<"\n";
}