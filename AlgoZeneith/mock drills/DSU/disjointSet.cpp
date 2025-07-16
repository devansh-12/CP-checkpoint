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

