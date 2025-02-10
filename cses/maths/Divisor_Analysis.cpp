#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int sz = 1e6+1;

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

int binMultiply(long long int a , long long int b){
    long long ans=0; // as ans get added 
  while(b>0){
    //see if set-bit than  add in ans
    if(b&1){
        ans=(ans+a)%mod;
    }
    a = (a+a)%mod;  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}


int binExp(int a , int b){
    int ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=binMultiply(ans,a) ;
    }
    a = binMultiply(a,a); 
    b>>=1 ; //right-shift the bit
  }
  return ans;
}

int sumofDivisors(vector<int> &primes,vector<int> &powers)
{
    int res=1;
    for(size_t i=0;i<(powers.size());i++){
        res = (res*1LL*(binExp(primes[i],powers[i]+1)-1))%mod;
        res = (res*1LL*(modInverse(primes[i]-1,mod)))%mod;
    }
    return res;
    
}
int numofDivisors(vector<int> &powers)
{
    int res =1;
    for(size_t i=0;i<(powers.size());i++){
        res = (res*1LL*(powers[i]+1)) % mod;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> primes(n), powers(n);
    int oddExponent = -1;

    for (int i = 0; i < n; i++) {
        cin >> primes[i] >> powers[i];
        if (powers[i] % 2 == 1) oddExponent = i;
    }

    ll outerExponent = 1, pdtofDivisors = 1;
    vector<ll> powerMod(n);

    if (oddExponent != -1) {
        for (int i = 0; i < n; i++) {
            if (i == oddExponent) {
                outerExponent = (outerExponent * 1LL * ((powers[i] + 1) / 2)) % (mod - 1);
            } else {
                outerExponent = (outerExponent * 1LL * (powers[i] + 1)) % (mod - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            powerMod[i] = (powers[i] * 1LL * outerExponent) % (mod - 1);
            pdtofDivisors = (pdtofDivisors * 1LL * binExp(primes[i], powerMod[i])) % mod;
        }
    } else {
        for (int i = 0; i < n; i++) {
            outerExponent = (outerExponent * 1LL * (powers[i] + 1)) % (mod - 1);
        }

        for (int i = 0; i < n; i++) {
            powerMod[i] = ((powers[i] / 2) * 1LL * outerExponent) % (mod - 1);
            pdtofDivisors = (pdtofDivisors * 1LL * binExp(primes[i], powerMod[i])) % mod;
        }
    }

    cout << numofDivisors(powers) << " " << sumofDivisors(primes, powers) << " " << pdtofDivisors << endl;
    return 0;
}