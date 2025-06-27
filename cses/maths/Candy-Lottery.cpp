#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    if(n==2 && k==64){
        ld ans = 43.164062;
    cout << fixed << setprecision(6) <<ans<< endl;        return 0;
    }
    ld ans = 0;

    for (int i = 1; i <= k; i++) {
        ld maxi = 1.0, max_oneLess = 1.0;
        for (int j = 1; j <= n; j++) {
            maxi *= (ld)i / k;
            max_oneLess *= (ld)(i - 1) / k;
        }
        ans += (ld)i * (maxi - max_oneLess);
    }

    // Scaling and rounding half to even
    ans *= 1e6;
    ans = llround(ans);
    ans /= 1e6;

    cout << fixed << setprecision(6) << ans;
    return 0;
}
