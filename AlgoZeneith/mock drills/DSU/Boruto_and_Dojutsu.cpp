#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent,size;
    vector<set<int>> colors;
    public:
    disjointSet(int n,vector<int>& colorList){
        parent.resize(n+1);
        size.resize(n+1,1);
        colors.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            colors[i].insert(colorList[i]);
        }
    }
    int findAnc(int node){
        if(node == parent[node]){return node;}

        return parent[node] = findAnc(parent[node]);
    }
    void merge(int u,int v){
        int pu = findAnc(u);
        int pv = findAnc(v);
        if(pu==pv){return;}
        if(size[pu] > size[pv]){
            swap(pu,pv);
        }
        size[pv] += size[pu];
        for(int c:colors[pu]){
            colors[pv].insert(c);
        }
        parent[pu] = pv;
        size[pu]=0;
        colors[pu].clear();
        
    }
    int getcolors(int node){
        return colors[findAnc(node)].size();
    }
};

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> colors(n+1);
    vector<pair<int,int>> edges;
    //vector<pair<int,int>> delEdges;
    vector<pair<int,int>> queries;
    vector<int> remaining(m+1,1);
    vector<int> result;

    for(int i=1;i<=n;i++){
        cin>>colors[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        queries.push_back({u,v});
        if(u==1){
            
            remaining[v-1]=0;
        }
        else{
            
        }
    }
    
    disjointSet ds(n,colors);
    for(int i=0;i<m;i++){
        if(remaining[i] == 1){
            ds.merge(edges[i].first,edges[i].second);
        }
    }
    for(int i=q-1;i>=0;i--){
        if(queries[i].first == 1){
            auto [u,v] = edges[queries[i].second - 1];
            ds.merge(u,v);
        }
        else{
            //cout<<ds.getcolors(queries[i].second)<<endl;
            result.push_back(ds.getcolors(queries[i].second));
        }
    }

    reverse(result.begin(), result.end());
    for (int x : result) {
        cout << x << '\n';
    }

    return 0;
}
