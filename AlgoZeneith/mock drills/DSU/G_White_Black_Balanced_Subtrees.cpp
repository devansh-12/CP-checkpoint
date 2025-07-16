#include<bits/stdc++.h>
using namespace std;

// res , cnt
pair<int,int> dfs(int curr,vector<vector<int>> &adj,string s){
    /*if(adj[curr].size()==0){
        return ;
    } */
    int res = 0,cnt=0;
    for(int node : adj[curr]){
        auto[r,c] = dfs(node,adj,s);
        res+=r;
        cnt+=c;
    }
    if(s[curr-1]=='B'){
        res+=1;
    }
    else{res-=1;}
    if(res == 0){cnt+=1;}
    return {res,cnt};

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int a;
            cin>>a;
            adj[a].push_back(i+2);
        }
        string s;
        cin>>s;
        auto[res,cnt] = dfs(1,adj,s);
        cout<<cnt<<endl;
    }

    return 0;
}