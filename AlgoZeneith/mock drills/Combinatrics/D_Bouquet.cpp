#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
ll binExp(int,int);

ll modInv(int n){
    return binExp(n,mod-2);
}

ll ncr(ll n,ll r){
    if(r<0 || n<r)return 0;
    if(r>n-r){r=n-r;}
    ll res = 1;

    for(int i=1;i<=r;i++){
        res = res * ((n-r+i)*modInv(i)%mod)%mod;
    }
    return res ;

}

ll binExp(int a,int b){
    if(b==0)
    return 1;
    ll half = binExp(a,b/2);
    if(b&1)return (((half*half)%mod)*a)%mod;
    return (((half*half)%mod))%mod;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int res = (binExp(2,n) - ncr(n,a) - ncr(n,b) - 1 +2*mod)%mod;
    if(res < 0){cout<<0<<endl;return 0;}
    cout<<res<<endl;
    return 0;
}