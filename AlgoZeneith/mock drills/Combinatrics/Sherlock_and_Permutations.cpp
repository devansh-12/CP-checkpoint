#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int sz = 2e3;

vector<int> fact(sz+1,1),invFact(sz+1,1);

int binExp(int a , int b){
    if(b==0)return 1;
    if(b==1)return a;

    long long half = binExp(a,b/2);
    if(b&1)
    return (int)(half*half%mod*a%mod );

    return (int)(half * half % mod);
}

int modInv(int n){
    return binExp(n,mod-2);
}

void precompute(){
    for(int i=1;i<=sz;i++){
        fact[i] = fact[i-1]*1LL*i%mod;
    }

    invFact[sz] = modInv(fact[sz]);

    for(int i=sz-1;i>=0;i--){
        invFact[i]= invFact[i+1]*1LL*(i+1)%mod;
    }
}

int ncr(int n,int r){
    if(r<0 || r>n)return 0;

    return (int) (fact[n]*1LL*invFact[n-r]%mod*invFact[r]%mod);
}

int main(){
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<ncr(n+m-1,n) <<endl;
    }
    
    return 0;
}