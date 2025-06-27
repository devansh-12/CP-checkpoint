#include<bits/stdc++.h>
using namespace std;

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

long long summation(long long n){
    return ((((n%mod)*((n+1)%mod))%mod)*modInverse(2,mod))%mod;
}

int main(){
    long long n;
    cin>>n;
    long long r=1,l=0,ans=0;
    while(r<=n){
        r = n/(n/r);
        long long diff = (summation(r) - summation(l) + mod) % mod;
        ans = (ans + ((n / r) * diff) % mod) % mod;
        //cout<<summation(r)-summation(l)<<" "<<(n/r)<<" ";
        l=r;
        r++;
    }
    cout<<ans<<endl;
    return 0;

}