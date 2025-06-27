#include<bits/stdc++.h>
using namespace std;

int log2func(long long x) {
    if (x <= 1) return 0;
    return (int)ceil(log2(x));
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long long  m,n,a,b;
        cin>>m>>n>>a>>b;
        if(m==1 && n==1 ){
            cout<<0;
            continue;
        }
        vector<pair<int,int>> possibleDimensions ;
        possibleDimensions.push_back({a,n});possibleDimensions.push_back({b,m});
        possibleDimensions.push_back({n-b+1,m});possibleDimensions.push_back({m-a+1,n});
        int res = INT_MAX;
        for(auto it : possibleDimensions){
            int ans = 0;
            ans += log2func(it.first);
            ans += log2func(it.second);
            res = min(res,ans+1);
        }
        cout<<res<<"\n";

    }
  
    return 0;
}