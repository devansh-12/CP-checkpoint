#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MOD1 = 1e9+6;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> primes(n), powers(n);
    for (int i = 0; i < n; i++) {
        cin >> primes[i] >> powers[i];
    }

    // Number of divisors
    ll numofDivisors = 1;
    for (int i = 0; i < n; i++) {
        numofDivisors = (numofDivisors * (powers[i] + 1)) % MOD;
    }

    // Sum of divisors
    ll sumofDivisors = 1;
    for (int i = 0; i < n; i++) {
        ll numerator = 1, base = primes[i], exp = powers[i] + 1;
        while (exp > 0) {
            if (exp & 1) numerator = (numerator * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        numerator = (numerator - 1 + MOD) % MOD;
        ll denominator = primes[i] - 1;
        ll inv = 1, mod0 = MOD, x0 = 0, x1 = 1;
        while (denominator > 1) {
            ll q = denominator / mod0;
            ll t = mod0;
            mod0 = denominator % mod0;
            denominator = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += MOD;
        denominator = x1;

        ll temp = (numerator * denominator) % MOD;
        sumofDivisors = (sumofDivisors * temp) % MOD;
    }

    // Product of divisors
    ll prodofDivisors = 1;
    ll outerExponent = 1, flag = 0;
    for (int i = 0; i < n; i++) {
        if (powers[i] % 2 == 1 && flag == 0) {
            outerExponent = (outerExponent * ((powers[i] + 1) / 2)) % MOD1;
            flag = 1;
        } else {
            outerExponent = (outerExponent * (powers[i] + 1)) % MOD1;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < n; i++) {
            powers[i] /= 2;
        }
    }
    ll base = 1;
    for (int i = 0; i < n; i++) {
        ll exp = powers[i], res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * primes[i]) % MOD;
            primes[i] = (primes[i] * primes[i]) % MOD;
            exp >>= 1;
        }
        base = (base * res) % MOD;
    }
    ll exp = outerExponent;
    while (exp > 0) {
        if (exp & 1) prodofDivisors = (prodofDivisors * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }

    cout << numofDivisors << " " << sumofDivisors << " " << prodofDivisors << endl;
    return 0;
}
