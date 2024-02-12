#include <iostream>
#include <vector>
using namespace std;
struct Group{
    int num;
    int size;
    Group(){}
};
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        vector<bool> possible(n+5,false);
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }
        vector<Group> groups;
        Group cur;
        cur.num = nums[0];
        cur.size = 1;
        for(int i = 1; i < n; i++){
            if(cur.num==nums[i]){
                cur.size++;
            }else{
                groups.push_back(cur);
                cur.num = nums[i];
                cur.size = 1;
            }
        }groups.push_back(cur);
        vector<int> queue(n+5,-1); 
        int index = 0;
        for(int i = 0; i < groups.size(); i++){
            index+=groups[i].size;
            if(groups[i].size>=2){
                possible[groups[i].num]=1;
            }else{
                if(queue[groups[i].num]!=-1){
                    if((index-groups[i].size)-queue[groups[i].num]<groups[i].size+1){
                        possible[groups[i].num]=1;
                    }
                    queue[groups[i].num]=index;
                }else{
                    queue[groups[i].num]=index;
                }
            }
        }

        bool anyPossible = false;
        for(int i = 1; i <= n; i++){
            if(possible[i]){
                cout<<(anyPossible?" ":"")<<i;
                anyPossible=true;
            }
        }
        if(!anyPossible){
            cout<<-1;
        }
        cout<<"\n";
        /*
        for(int i = 0; i < groups.size(); i++){
            cout<<groups[i].num<<" : "<<groups[i].size<<"\n";
        }*/
    }

}