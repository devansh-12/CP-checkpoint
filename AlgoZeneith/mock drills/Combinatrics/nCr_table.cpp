#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e3;
const int mod = 1e9;
vector<vector<ll>> nCr(sz+1,vector<ll> (sz+1,0));

void precompute(){
    for(int i=0;i<=sz;i++){
        nCr[i][0] = 1;
    }
    
    for(int i=1;i<=sz;i++){
        
        for(int j=1;j<=i;j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%mod;
        }
    }
}

int main(){
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n;
        cin>>n;
        
        for(int i=0;i<=n;i++)
        cout<<nCr[n][i]<<" ";
        
        cout<<endl;
    }
    return 0;
}