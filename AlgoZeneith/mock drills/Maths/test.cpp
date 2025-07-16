
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
    int findAnc(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findAnc(parent[node]);
    }
    void unionbyRank(int u,int v){
        int ulp_v = findAnc(v);
        int ulp_u = findAnc(u);
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
        return findAnc(u)==findAnc(v);
    }

};


int main(){
    int m,n,k;
    cin>>m>>n>>k;
    disjointSet ds(m);
    vector<tuple<string, int, int>> ips;
    string s;
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       if(a<b)
       st.insert({a,b});
       else
       st.insert({b,a});
    }
    
    string type;
    int u, v;

    for (int i = 0; i < k; i++) {
    cin >> type >> u >> v;
    ips.push_back({type, u, v});
    if(type=="cut"){
            if(u<v)
            st.erase({u,v});
            else
            st.erase({v,u});
        }
    }

    for(auto &it : st){
        ds.unionbyRank(it.first,it.second);
    }

    vector<string> ans;
    for (int i = k - 1; i >= 0; i--) {
        auto [type, u, v] = ips[i];
        if (type == "ask") {
            ans.push_back(ds.ask(u, v) ? "YES" : "NO");
        } else {
            ds.unionbyRank(u, v); 
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &it:ans){
        cout<<it<<"\n";
    }
    return 0;
}