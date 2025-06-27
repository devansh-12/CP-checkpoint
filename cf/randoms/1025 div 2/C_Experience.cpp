#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> rank,parent;
    vector<long> val,lazyAdd;
    vector<vector<int>> members;

    public:
    disjointSet(int V){
        parent.resize(V+1,0);
        //rank.resize(V+1,0);
        val.resize(V+1,0);
        lazyAdd.resize(V+1,0);
        members.resize(V+1);
        for(int i=0;i<=V;i++){
            parent[i]=i;
            members[i].push_back(i);
        }
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_v = findUpar(v);
        int ulp_u = findUpar(u);
        if(ulp_v==ulp_u){
            return ;
        }
        if(members[ulp_u].size() > members[ulp_v].size()){
            swap(ulp_u,ulp_v);
        }
        for (int x : members[ulp_u]) {
            val[x] += (lazyAdd[ulp_u] - lazyAdd[ulp_v]);
            members[ulp_v].push_back(x);
        }
        //members[ulp_u].clear();
        //add[ulp_u] = 0;
        parent[ulp_u] = ulp_v;
    }

    void add(int u,int amt){
        int root = findUpar(u);
        lazyAdd[root] += amt;
    }
    int get(int node){
        int root = findUpar(node);
        return val[node] + lazyAdd[root];
    }

};

int main(){
    int m,n;
    cin>>m>>n;
    disjointSet ds(m);
    for(int i=0;i<n;i++){
        string s;
        int a,b;
        cin>>s;
        if(s=="add"){
            cin>>a>>b;
            ds.add(a,b);
        }
        else if(s=="join"){
            cin>>a>>b;
            ds.unionByRank(a,b);
        }
        else{
            cin>>a;
            cout<<ds.get(a)<<"\n";
        }
    }
    return 0;
}