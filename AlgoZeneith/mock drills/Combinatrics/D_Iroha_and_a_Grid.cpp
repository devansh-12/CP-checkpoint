#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
const int N = 2e5;
vector<ll> fact(N+1,1),invFact(N+1,1);

ll binExp(int a,int b){
    if(b==0)return 1;

    ll half = binExp(a,b/2);
    if(b&1){
        return half*half%mod*a%mod;
    }
    return half*half%mod;
}

ll modInv(int a){
    return binExp(a,mod-2);
}

void precompute(){
    for(int i=1;i<=N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    invFact[N]=modInv(fact[N]);
    for(int i=N-1;i>=0;i--){
        invFact[i]=invFact[i+1]*(i+1)%mod;
    }
}

ll ncr(int n,int r){
    if(r < 0 || r > n) return 0;
    return invFact[n-r]*invFact[r]%mod*fact[n]%mod;
}

int main(){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    precompute();
    ll res = 0;
    for(int i=b;i<w;i++){
        res = (res + (ncr(h-a-1+i,i) * ncr(w+a-2-i,a-1))%mod)%mod;
    }
    cout<< res <<endl;
}