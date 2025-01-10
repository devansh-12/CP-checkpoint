#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mod = 1e9+7;

vector<vector<ll>> matMul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    int R1 = a.size();
    int C1 = a[0].size();
    int R2 = b.size();
    int C2 = b[0].size();
    vector<vector<ll>> result(R1, vector<ll>(C2, 0));
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < R2; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return result;
}

vector<vector<ll>> matExpoIterative(vector<vector<ll>> M, int n) {
    int size = M.size();
    vector<vector<ll>> result(size, vector<ll>(size, 0));

    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while (n > 0) {
        if (n % 2 == 1) {
            result = matMul(result, M); 
        }
        M = matMul(M, M); 
        n /= 2;
    }

    return result;
}

