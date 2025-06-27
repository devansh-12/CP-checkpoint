#include <bits/stdc++.h>
using namespace std;

const long long INF = INT_MAX;
const long long NINF = INT_MIN;

struct Node {
    Node *l = nullptr, *r = nullptr;
    int lo, hi;
    long long mset = INF, madd = 0, val = 0;

    Node(int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
            val = l->val + r->val;
        }
    }

    Node(vector<long long>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = l->val + r->val;
        } else {
            val = v[lo];
        }
    }

    long long query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }

    void set(int L, int R, long long x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            madd = 0;
            val = x * (hi - lo);
        } else {
            push();
            l->set(L, R, x);
            r->set(L, R, x);
            val = l->val + r->val;
        }
    }

    void add(int L, int R, long long x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != INF) {
                mset += x;
            } else {
                madd += x;
            }
            val += x * (hi - lo);
        } else {
            push();
            l->add(L, R, x);
            r->add(L, R, x);
            val = l->val + r->val;
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != INF) {
            l->set(lo, hi, mset);
            r->set(lo, hi, mset);
            mset = INF;
        } else if (madd) {
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    cin >> m >> n;
    vector<long long> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    Node* root = new Node(arr, 0, m);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            root->set(b, b + 1, c);
        } else {
            cout << root->query(b, c) <<endl;
        }
    }

    return 0;
}
