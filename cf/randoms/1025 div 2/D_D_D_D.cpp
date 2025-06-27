#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,m,n;
        cin>>n>>m>>l;
        int minodd = INT_MAX;
        vector<int> evens,odds;
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            if(x%2==0){
                evens.push_back(x);
            }
            else{
                minodd = min(minodd,x);
                odds.push_back(x);
            }
        }
        long long oddsum,evenSum;
        oddsum = accumulate(odds.begin(),odds.end(),0LL);
        evenSum = accumulate(evens.begin(),evens.end(),0LL);

        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q1;
        q1.push({1,0});
        vector<vector<int>> distance(n+1,vector<int>(2,-1));
        distance[1][0]=0;
        while(!q1.empty()){
            int sz = q1.size();

            for(int i=0;i<sz;i++){
                auto [node,dist] = q1.front();
                q1.pop();
                
                bool isEven = ((dist+1)%2==0);
                for(auto e :adj[node]){
                    if(isEven && distance[e][0]==-1){
                        q1.push({e,dist+1});
                        distance[e][0]=dist+1;
                    }
                    if(!isEven && distance[e][1]==-1){
                        q1.push({e,dist+1});
                        distance[e][1]=dist+1;
                    }
                }

            }

        }
        for(int i=1;i<=n;i++){
            int p=0;
            if(odds.size()%2==0){
                if(distance[i][0]!=-1 && distance[i][0]<=evenSum+oddsum){
                    p=1;
                }
                if(odds.size()!=0 &&distance[i][1]!=-1 && distance[i][1]<=evenSum+oddsum-minodd)
                p=1;
            }
            else{
                if(distance[i][0]!=-1 && distance[i][0]<=evenSum+oddsum-minodd){
                    p=1;
                }
                if(distance[i][1]!=-1 && distance[i][1]<=evenSum+oddsum)
                p=1;
            }
            cout<<p;
        }
        cout<<endl;
    }

    return 0;
}