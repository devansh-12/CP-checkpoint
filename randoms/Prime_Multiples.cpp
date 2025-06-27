#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vll a(k);

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    for (int i = 1; i < (1ll << k); i++) {  // Start from 1 to avoid empty subset
        ll prod = 1, bits = 0;

        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {  
                bits++;
                if (prod > n / a[j]) { // Prevent overflow
                    prod = n + 1;
                    break;
                }
                prod *= a[j];
            }
        }

        if (prod <= n) {
            if (bits % 2 == 1) ans += n / prod; // Odd-sized subset: Add
            else ans -= n / prod;               // Even-sized subset: Subtract
        }
    }

    cout << ans << "\n";
}
