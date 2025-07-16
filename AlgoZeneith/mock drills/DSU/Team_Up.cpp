#include <bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent,size,sum;
    int N ;

    public: 
    disjointSet(int n){
        N=n;
        parent.resize(2*n+2);
        size.resize(2*n+2);
        sum.resize(2*n+2);

        // 1 -> n actual players mapped to teams 
        // n+1 -> 2n Team ka DSU  
        // actual players have no size/sum , Teams have 
        for(int i=1;i<=n;i++){
            sum[i+n] = i;
            parent[i] = parent[i+n] = i+n;
            size[i+n] = 1;
        }
    }

    int findAnc(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findAnc(parent[node]);
    }

    void merge(int u,int v){
        int pv = findAnc(v);
        int pu = findAnc(u);
        if(pu == pv){
            return ;
        }
        if(size[pu] > size[pv]){
            swap(pu,pv);
        }
        size[pv] += size[pu];
        size[pu] = 0;
        parent[pu] = pv;
        sum[pv] += sum[pu];
        sum[pu] = 0;
    }

    int getSize(int node){
        return size[findAnc(node)];
    }

    int getSum(int node){
        return sum[findAnc(node)];
    }

    void move(int a,int b){
        int pa = findAnc(a);
        int pb = findAnc(b);
        if(pa == pb)return;
        sum[pa] -= a;
        sum[pb] += a;
        size[pa]--;
        size[pb]++;
        parent[a] = pb;
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        disjointSet ds(n);
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a;

            if(a==2){
                cin>>b;
                cout<<ds.getSize(b)<<" "<<ds.getSum(b)<<endl;
            }
            else{
                cin>>b>>c;
                if(a==1){
                    ds.merge(b,c);
                }
                if(a==3){
                    ds.move(b,c);
                }
            }
        }
    }
    return 0;
}