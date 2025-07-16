#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent,size;
    map<pair<int,int>,int> mismatch;
    int cost ;
    public:
    disjointSet(int n,map<pair<int,int>,int> &mismatch,int cost){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
        this->mismatch = mismatch;
        this->cost = cost;
    }

    void merge(int u,int v){
        int pu = findAnc(u);
        int pv = findAnc(v);
        if(pu == pv)return ;

        if(size[pu] > size[pv])swap(pu,pv);
        // pv > pu always
        size[pv] += size[pu];
        size[pu] = 0;
        parent[pu] = pv;

        // mismatch check must be done after merge idiot
        vector<pair<int,int>> removes;
        for (auto &[p, cnt] : mismatch) {
        int x = p.first;
        int y = p.second;
        if (findAnc(x) == findAnc(y)) {
            cost -= cnt;
            removes.push_back(p);
        }
        }
        for(auto p:removes){
            mismatch.erase(p);
        }
    }

    int findAnc(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findAnc(parent[node]);
    }

    int getCost(){
        return cost;
    }
};

int main(){
    int n;
    string s;
    cin>>n>>s;
    int q;
    cin>>q;
    
    map<pair<int,int>, int> mismatch;
    int total_cost = 0;

    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        int u = s[l] - 'a';
        int v = s[r] - 'a';
        if (u == v) continue;
        total_cost++;
        int a = min(u,v), b = max(u,v);
        mismatch[{a,b}]++;
    }
    disjointSet ds(26,mismatch,total_cost);

    for(int i=0;i<q;i++){
        int a;
        char b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            int u,v;
            u = b - 'a';
            v = c - 'a';
            ds.merge(u,v);

        }else{
            
            cout<<ds.getCost()<<endl;
        }
    }
    return 0;
}