#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> rank,parent;
    public:
    disjointSet(int V){
        parent.resize(V+1,0);
        rank.resize(V+1,0);
        for(int i=0;i<=V;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    void unionbyRank(int u,int v){
        int ulp_v = findUpar(v);
        int ulp_u = findUpar(u);
        if(ulp_v == ulp_u){return;}
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        else{
            parent[ulp_u]=ulp_v;
        }

    }
    bool ask(int u,int v){
        return findUpar(u)==findUpar(v);
    }

};


int main(){
    int m,n,k;
    cin>>m>>n>>k;
    disjointSet ds(m);
    vector<tuple<string, int, int>> ips;
    string s;
    set<pair<int,int>> s1;
    for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       if(a<b)
       s1.insert({a,b});
       else
       s1.insert({b,a});
    }
    
    string type;
    int u, v;

    for (int i = 0; i < k; i++) {
    cin >> type >> u >> v;
    ips.push_back({type, u, v});
    if(type=="cut"){
            if(u<v)
            s1.erase({u,v});
            else
            s1.erase({v,u});
        }
    }

    for(auto &it : s1){
        ds.unionbyRank(it.first,it.second);
    }

    vector<string> res;
    for (int i = k - 1; i >= 0; i--) {
        auto [type, u, v] = ips[i];
        if (type == "ask") {
            res.push_back(ds.ask(u, v) ? "YES" : "NO");
        } else {
            ds.unionbyRank(u, v); 
        }
    }
    reverse(res.begin(), res.end());
    for(auto &it:res){
        cout<<it<<"\n";
    }
    return 0;
}