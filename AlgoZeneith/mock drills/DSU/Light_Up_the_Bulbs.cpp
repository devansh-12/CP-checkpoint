#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void merge(int u,int v){
        int uu = findPar(u);
        int uv = findPar(v);
        if(uu == uv)return ;
        if(size[uu] < size[uv]){
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else{
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }

};

int main(){
    int n;
    cin>>n;
    DisjointSet ds(n);
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        int x1,y1;
        x1 = p[i].first;
        y1 = p[i].second;
        for(int j=i+1;j<n;j++){
            int x2,y2;
            x2 = p[j].first;
            y2 = p[j].second;
            int dist = pow((x2-x1),2)+pow((y2-y1),2);
            edges.push_back({dist,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());

    long long sum =0;
    for(auto edge:edges){
        int u,v,wt;
        u = edge.second.first;
        v = edge.second.second;
        wt = edge.first;
        if(ds.findPar(u) != ds.findPar(v) ){
            ds.merge(u,v);
            sum += wt;
        }

    }
    cout<<sum<<endl;

    return 0;
}