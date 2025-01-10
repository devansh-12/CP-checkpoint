#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mod = 1e9+7;

vector<vector<ll>> mulMat(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    int R1 = a.size();
    int C1 = a[0].size();
    int R2 = b.size();
    int C2 = b[0].size();
    vector<vector<ll>> result(R1, vector<ll>(C2, 0));
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < R2; k++) {
                result[i][j] = (result[i][j] + ((a[i][k] * b[k][j]) % mod)) % mod;
            }
        }
    }
    return result;
}

vector<vector<ll>> matExpo(vector<vector<ll>> &M, ll n) {
    vector<vector<ll>> result(6, vector<ll>(6, 0));
    for (int i = 0; i < 6; i++) result[i][i] = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result = mulMat(result, M);
        }
        M = mulMat(M, M);
        n /= 2;
    }

    return result;
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> initial = {{16}, {8}, {4}, {2}, {1}, {1}};
    vector<vector<ll>> M = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    ll ans;
    if (n <= 5) {
        ans = initial[5 - n][0];
    } else {
        vector<vector<ll>> res = mulMat(matExpo(M, n - 5), initial);
        ans = res[0][0];
    }

    cout << ans << endl;
    return 0;
}
