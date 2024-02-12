#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n;
struct Move{
    int from; 
    int to; 
    ll amount;
    int time;
    Move(){}
    Move(int f, int t, ll a, int time):from(f),to(t),amount(a),time(time){}
    bool operator==(const Move& other) const {
        return from==other.from && to==other.to;
    }
    struct Hash{
        size_t operator()(const Move& m) const {
            return hash<int>{}(m.from)^hash<int>{}(m.to);
        }
    };
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll hay[200005], hayCopy[200005];
    int degrees[200005], times[200005];
    vector<int> leaves;
    vector<vector<int>> graph(n);
    vector<unordered_set<int>> connections(n);
    ll totalHay = 0, equalHay;
    for(int i = 0; i < n; i++){
        cin>>hay[i];
        totalHay+=hay[i];
        hayCopy[i]=hay[i];
    }
    equalHay=totalHay/(ll)n;
    bool isLinked=true;
    for(int i = 0; i < n-1; i++){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(max(a,b)-min(a,b)!=1){isLinked=false;}
        degrees[a]++;
        degrees[b]++;
        connections[a].insert({b});
        connections[b].insert({a});
    }
    if(isLinked){
        vector<Move> moves;
        bool request = false;
        ll requestA = 0;
        ll savedA = 0;
        for(int i = 0; i < n; i++){
            if(!request){
                if(hay[i]<equalHay){
                    request=true;
                    requestA = equalHay-hay[i];
                }else if(hay[i]>equalHay){
                    moves.push_back(Move(i,i+1,hay[i]-equalHay,0));
                    hay[i+1]+=hay[i]-equalHay;
                    hay[i]=equalHay;
                }
            }else if(request){
                int j = i;
                ll lastR; 
                while(requestA > savedA){
                    if(hay[j]<equalHay){
                        requestA+=equalHay-hay[j];
                    }else{
                        savedA+=hay[j]-equalHay;
                        lastR=hay[j]-equalHay;
                    }
                    j++;
                }
                j--;
                int k = j;
                savedA-=lastR;
                ll ac = requestA-savedA;
                while(j!=i-2){
                    if(hay[j]>equalHay){
                        moves.push_back(Move(j,j-1,ac,0));
                        hay[j]-=ac;
                        ll temp = hay[j-1];
                        hay[j-1]+=ac;
                        ac=abs(equalHay-hay[j-1]);
                    }
                    j--;
                }
                request=false;
                requestA=0;
                savedA=0;
                i=k-1;
            }
        }
        cout<<moves.size()<<"\n";
        for(int i = 0; i < moves.size(); i++){
            cout<<moves[i].from+1<<" "<<moves[i].to+1<<" "<<moves[i].amount<<"\n";
        }
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(degrees[i]==1){
            leaves.push_back(i);
        }
    }
    unordered_set<Move,Move::Hash> moveSet;
    vector<Move> moves;
    for(int i = 0; i < leaves.size(); i++){
        //inserting move from leaf to parent
        if(connections[leaves[i]].empty()){continue;}
        int p = *connections[leaves[i]].begin();
        connections[p].erase(leaves[i]);
        degrees[p]--;
        if(degrees[p]==1){
            leaves.push_back(p);
        }
        Move m;
        ll a;
        if(hay[leaves[i]]<equalHay){
            a=equalHay-hay[leaves[i]];
            m = Move(p,leaves[i],a,hay[p]-a<0?-1:0);
            hay[p]-=a;
        }else if(hay[leaves[i]]>equalHay){
            a=hay[leaves[i]]-equalHay;
            m = Move(leaves[i],p,a,100000); 
            hay[p]+=a;
        }else{
            continue;
        }
        if(moveSet.find(m)==moveSet.end()){
            moveSet.insert({m});
            moves.push_back(m);
        }
    }
    //stable_sort(moves.begin(),moves.end(),[](const Move &a, const Move &b){return a.time>b.time;});
    cout<<moves.size()<<"\n";
    list<Move> buffer;
    for(int i = 0; i < moves.size(); i++){
        if(hayCopy[moves[i].from]>moves[i].amount){
            cout<<moves[i].from+1<<" "<<moves[i].to+1<<" "<<moves[i].amount<<"\n";
            hayCopy[moves[i].from]-=moves[i].amount;
            hayCopy[moves[i].to]+=moves[i].amount;
        }else{
            //buffer.insert(buffer.end(),moves[i]);
            buffer.push_back(moves[i]);
        }
        for(list<Move>::reverse_iterator it=buffer.rbegin(); it!=buffer.rend();){
            if(hayCopy[it->from]>it->amount){
                cout<<it->from+1<<" "<<it->to+1<<" "<<it->amount<<"\n";
                hayCopy[it->from]-=it->amount;
                hayCopy[it->to]+=it->amount;
                it=(decltype(it))buffer.erase(next(it).base());
                //buffer.erase(next(it).base());
                //it=buffer.rbegin();
            }else{
                it--;
            }
        }
    }
    bool s=false;
    while(!buffer.empty()){
        list<Move>::iterator it = buffer.begin();
        list<Move>::reverse_iterator itR = buffer.rbegin();
        while(!(*it==*itR)){
            if(s){
                if(hayCopy[it->from]>it->amount){
                    cout<<it->from+1<<" "<<it->to+1<<" "<<it->amount<<"\n";
                    hayCopy[it->from]-=it->amount;
                    hayCopy[it->to]+=it->amount;
                    it=buffer.erase(it);
                }
                else{
                    it++;
                }
            }else{
                if(hayCopy[itR->from]>itR->amount){
                    cout<<itR->from+1<<" "<<itR->to+1<<" "<<itR->amount<<"\n";
                    hayCopy[itR->from]-=itR->amount;
                    hayCopy[itR->to]+=itR->amount;
                    itR=(decltype(itR))buffer.erase(next(itR).base());
                }
                else{
                    itR--;
                }
            }
            s=!s;
        }
        /*
        if(s){
            for(list<Move>::iterator it=buffer.begin(); it!=buffer.end();){
                if(hayCopy[it->from]>it->amount){
                    cout<<it->from+1<<" "<<it->to+1<<" "<<it->amount<<"\n";
                    hayCopy[it->from]-=it->amount;
                    hayCopy[it->to]+=it->amount;
                    it=buffer.erase(it);
                    //buffer.erase(it);
                    //it=buffer.begin();
                }else{
                    it++;
                }
            }
        }else{
            for(list<Move>::reverse_iterator it=buffer.rbegin(); it!=buffer.rend();){
                if(hayCopy[it->from]>it->amount){
                    cout<<it->from+1<<" "<<it->to+1<<" "<<it->amount<<"\n";
                    hayCopy[it->from]-=it->amount;
                    hayCopy[it->to]+=it->amount;
                    it=(decltype(it))buffer.erase(next(it).base());
                    //buffer.erase(next(it).base());
                    //it=buffer.rbegin();
                }else{
                    it--;
                }
            }
        }
        s=!s;*/
    }
}
/*
#####
6
2 1 4 7 2 2
2 1
2 3
2 4
4 5
5 6

5
4 5 2
4 2 2
3 2 1
5 6 1
2 1 1
#####

#####
8
2 1 5 7 2 2 3 2
2 1
2 3
2 4
4 5
5 6
5 7
7 8

7
4 5 3
5 7 1
4 2 1
3 2 2
7 8 1
5 6 1
2 1 1
#####

9
2 4 5 7 2 2 3 2 0
2 1
2 3
2 4
4 5
5 6
5 7
7 8
9 6

8
4 5 6
2 4 2
3 2 2
5 7 1
7 8 1
2 1 1
5 6 4
6 9 3

#####

11
2 4 5 7 2 2 3 2 0 0 6
2 1
2 3
2 4
4 5
5 6
10 9
5 7
7 8
9 6
1 11

#####

5
3 1 2 7 2
1 2
2 3
3 4
4 5

3
4 3 3
3 2 2
4 5 1

#####

5
7 1 2 3 2
1 2
2 3
3 4
4 5

4
1 2 4
2 3 2
3 4 1
4 5 1

#####

6
1 0 5 3 6 3
1 2
2 3
5 6
3 4
4 5
*/