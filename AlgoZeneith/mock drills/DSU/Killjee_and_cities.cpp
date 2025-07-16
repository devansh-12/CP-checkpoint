#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent,size;
    int cnt ;
    public:
    disjointSet(int n){
        cnt = n -1;
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    void merge(int u,int v){
        int pu = findAnc(u);
        int pv = findAnc(v);
        if(pu == pv){return ;}
        cnt--;
        if(size[pu]>size[pv]){
            swap(pu,pv);
        }
        parent[pu] = pv;
        size[pv] += size[pu];
        size[pu]=0;


    }

    int findAnc(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findAnc(parent[node]);
    }
    int getCnt(){
        return cnt;
    }

};

int main(){
    int n;
    cin>>n;
    disjointSet ds(n); 
    int m,w;
    cin>>m>>w;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ds.merge(u,v);
        //cout<<ds.getCnt()<<" ";
    }
    int k;
    cin>>k>>w;
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        ds.merge(u,v);
        cout<<ds.getCnt()<<" ";
    }
    return 0;
}