#include<bits/stdc++.h>
using namespace std;

long long maxRects(long long n1, long long w, long long h) {
    long long w1, h1;
    w1 = n1 / w;
    h1 = n1 / h;
    return h1 * w1;
}

int main() {
    int n, h, w;
    cin >> h >> w >> n;

    long long max_Length = max(w, h);
    long long high = max_Length * (long long)ceil(sqrt((double)n)), low = 1;
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (maxRects(mid, w, h) > n) {
            ans = mid;
            high = mid - 1;
        } else if (maxRects(mid, w, h) < n) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << ans << endl;
}
