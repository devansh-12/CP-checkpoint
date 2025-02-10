#include<bits/stdc++.h>
using namespace std;

const int sz = 1e6+1;
const int mod = 1e9+7;

int modInverse(int a, int m) {
    int m0 = m, x0 = 0, x1 = 1;

    if (m == 1)
        return 0; // Inverse doesn't exist if modulo is 1

    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;

        // Update m and a
        m = a % m;
        a = t;

        // Update x0 and x1
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

vector<int> fact(sz),mmi(sz);

int main(){
    int t;
    cin>>t;
    fact[0]=1;
    mmi[0]=modInverse(1,mod);
    for(int i=1;i<sz;i++){
        fact[i]= (i*1LL*fact[i-1])%mod;
        mmi[i] = modInverse(fact[i],mod);
    }
    while(t--){
        int n,r;
        cin>>n>>r;
        cout<<(((fact[n]*1LL*mmi[n-r])%mod)*1LL*mmi[r])%mod<<endl;
    }
    
    return 0;
}