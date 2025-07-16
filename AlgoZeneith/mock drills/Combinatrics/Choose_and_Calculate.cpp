#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
const int MAX = 1e5;

vector<ll> fact(MAX+1,1),invFact(MAX+1,1);

ll binExp(int a,int b){
    if(b==0){return 1;}
    ll half = binExp(a,b/2);
    if(b&1){
        return (((half*half)%mod)*a)%mod;
    }
    return (half*half)%mod;
}

void precompute(){
    for(int i=1;i<=MAX;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    invFact[MAX] = binExp(fact[MAX],mod-2) ;

    for(int i=MAX-1;i>=0;i--){
        invFact[i]=(invFact[i+1]*(i+1))%mod;
    }
}

ll ncr(int n,int r){
    if(r<0 || r>n){return 0;}

    return (((fact[n]*invFact[n-r])%mod)*invFact[r])%mod;
}

int main(){
    precompute();
    int n,r;
    cin>>n>>r;
    vector<int> a(n);
    ll maxSum=0,minSum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        maxSum = (maxSum + (a[i]*ncr(i,r-1))%mod)%mod;
    }
    for(int i=0;i<n;i++){
        minSum = (minSum + (a[i]*ncr(n-i-1,r-1))%mod)%mod;
    }

    cout<<(maxSum - minSum + mod )%mod<<endl;
    return 0;
}