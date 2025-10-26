
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define int ll
#define sz(x) int(size(x))
#define _ << ' ' <<
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
 
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
 
#ifdef LOCAL
#include "/home/munhorgil/algo/debug.h"
#else
#define print(...) 42
#endif
 
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
 
vector<int> d(N, 1);
 
void Sieve() {
    int r = sqrt(N);
    vector<bool> incl(N, 0);
    for (int i = 2; i < r; i++) {
        if (incl[i]) continue;
        int q = i;
        int b = 1;
        while (q < N) {
            for (int j = 1; q * j < N; j++) {
                if (j % i == 0) continue;
                incl[q * j] = 1;
                d[q * j] *= (b + 1);
            }
            q *= i;
            b++;
        }
    }
    for (int i = r; i < N; i++) {
        if (!incl[i]) d[i] = 2;
    }
}
 
class SegmentTree {
public:
    vector<int> tree;
    vector<int> arr;
    int n;
    SegmentTree(vector<int>& a) {
        n = a.size();
        arr = a;
        tree = vector<int>(4 * n, 0);
        build(1, 0, n - 1);
    }
    int combine(int x, int y) {
        return gcd(x, y);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    void update(int v, int tl, int tr, int idx, int val) {
        if (idx < tl || idx > tr) {
            return;
        }
        if (tl == tr && tl == idx) {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, idx, val);
        update(2 * v + 1, tm + 1, tr, idx, val);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    int get(int l, int r) {
        int x = get(1, 0, n - 1, l, r);
        if (!x) return n;
        return d[x];
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l > tr || r < tl) {
            return 0;
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return combine(
            get(2 * v, tl, tm, l, min(r, tm)),
            get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
};
 
void Solve(int TEST) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            b[i + 1] = i + 1;
        }
    }
    SegmentTree st(b);
    int p, u;
    cout << st.get(0, n - 1) << endl;
    while (q--) {
        cin >> p >> u;
        p--;
        a[p] = u;
        if (p < n - 1) {
            if (a[p] > a[p + 1]) {
                st.update(p + 1, p + 1);
            } else {
                st.update(p + 1, 0);
            }
        }
        if (p > 0) {
            if (a[p - 1] > a[p]) {
                st.update(p, p);
            } else {
                st.update(p, 0);
            }
        }
        cout << st.get(0, n - 1) << endl;
    }
}
 
signed main() {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(0);
 
    Sieve();
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        Solve(i);
    }
}