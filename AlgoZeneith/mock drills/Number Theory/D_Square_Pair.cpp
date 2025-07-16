#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5;
vector<long long> hp(N + 1, 0);

void seive() {
    for (long long i = 2; i <= N; ++i) {
        if (hp[i] == 0) {
            for (long long j = i; j <= N; j += i) {
                if (hp[j] == 0)
                    hp[j] = i;
            }
        }
    }
}

long long factorise(long long x) {
    long long result = 1;
    while (x > 1) {
        long long pf = hp[x];
        long long pow = 0;
        while (x % pf == 0) {
            x /= pf;
            pow++;
        }
        if (pow % 2 != 0) {
            result *= pf;
        }
    }
    return result;
}

int main() {
    seive();
    long long n;
    cin >> n;

    vector<long long> arr(n);
    long long numZero = 0;
    unordered_map<long long, long long> freq;

    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 0) {
            numZero++;
        } else {
            long long factors = factorise(arr[i]);
            freq[factors]++;
        }
    }

    long long res = 0;

    for (auto &[val, count] : freq) {
        res += count * (count - 1) / 2;
    }

    res += numZero * (n - numZero); 
    res += numZero * (numZero - 1) / 2; 

    cout << res << '\n';
    return 0;
}
