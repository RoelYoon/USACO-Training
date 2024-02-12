/*
ID: roelyoon
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
void rotate90(vector<vector<bool>> &pattern){
    vector<vector<bool>> temp(n,vector<bool>(n));
    for(int r = n-1; r>=0; r--){
        for(int c = 0; c<n; c++){
            temp[c][(n-1)-r]=pattern[r][c];
        }
    }
    pattern=temp; 
}
void reflect(vector<vector<bool>> &pattern){
    vector<vector<bool>> temp(n,vector<bool>(n));
    for(int r = 0; r<n; r++){
        for(int c = 0; c<n; c++){
            temp[r][n-1-c]=pattern[r][c];
        }
    }
    pattern=temp;
}
bool match(vector<vector<bool>> &a, vector<vector<bool>> &b){
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(a[r][c]!=b[r][c]){
                return false;
            }
        }
    }
    return true;
}
bool trans1(vector<vector<bool>> original, vector<vector<bool>> &modified){
    rotate90(original);
    return match(original,modified);
}
bool trans2(vector<vector<bool>> original, vector<vector<bool>> &modified){
    rotate90(original);
    rotate90(original);
    return match(original,modified);
}
bool trans3(vector<vector<bool>> original, vector<vector<bool>> &modified){
    rotate90(original);
    rotate90(original);
    rotate90(original);
    return match(original,modified);
}
bool trans4(vector<vector<bool>> original, vector<vector<bool>> &modified){
    reflect(original);
    return match(original,modified);
}
bool trans5(vector<vector<bool>> original, vector<vector<bool>> &modified){
    reflect(original);
    for(int i = 0; i < 3; i++){
        rotate90(original);
        bool isMatch = match(original,modified);
        if(isMatch){
            return true;
        }
    }
    return false;
}
bool trans6(vector<vector<bool>> original, vector<vector<bool>> &modified){
    return match(original,modified);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("transform.in","r",stdin);
    //freopen("transform.out","w",stdout);
    cin>>n;
    vector<vector<bool>> original(n,vector<bool>(n));
    vector<vector<bool>> modified(n,vector<bool>(n));
    for(int i = 0; i < 2; i++){
        for(int r = 0; r < n; r++){
            string row; cin>>row;
            for(int c = 0; c < n; c++){
                bool element = row[c]=='@' ? false : true;
                switch(i){
                    case 0:
                        original[r][c]=element;
                        break;
                    case 1:
                        modified[r][c]=element;
                        break;
                }
            }
        }
    }
    int ans;
    if(trans1(original,modified)){ans=1;}
    else if(trans2(original,modified)){ans=2;}
    else if(trans3(original,modified)){ans=3;}
    else if(trans4(original,modified)){ans=4;}
    else if(trans5(original,modified)){ans=5;}
    else if(trans6(original,modified)){ans=6;}
    else{ans=7;}
    cout<<ans<<"\n";
}
/*
010
111
001

010
011
110
*/