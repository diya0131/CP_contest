#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define debug(n) cout << #n << " = " << n << endl;
#define int ll

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

class LazySegmentTree {
public:
    vector<int> tree;
    vector<int> lazy;
    int n;
    LazySegmentTree(int n) : n(n) {
        tree = vector<int>(4 * n, 0);
        lazy = vector<int>(4 * n, 0);
    }
    int combine(int x, int y) {
        return max(x, y);
    }
    void push(int v) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        tree[2 * v] += lazy[v];
        tree[2 * v + 1] += lazy[v];
        lazy[v] = 0;
    }
    void update(int l, int r) {
        update(0, n - 1, 1, l, r);
    }
    void update(int tl, int tr, int v, int l, int r) {
        if (l > r) {
            return;
        }
        if (tl == l && tr == r) {
            lazy[v]++;
            tree[v]++;
            return;
        }
        push(v);
        int m = (tl + tr) / 2;
        update(tl, m, 2 * v, l, min(m, r));
        update(m + 1, tr, 2 * v + 1, max(m + 1, l), r);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    int get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }
    int get(int l, int r, int tl, int tr, int v) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        push(v);
        int m = (tl + tr) / 2;
        return combine(get(l, min(m, r), tl, m, 2 * v), get(max(l, m + 1), r, m + 1, tr, 2 * v + 1));
    }
};

void Solve() {
    int n, m, x;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LazySegmentTree lst(m + 100);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            cnt++;
            continue;
        }
        if (abs(a[i]) > cnt) {
            continue;
        }
        if (a[i] < 0) {
            lst.update(0, m - abs(a[i]));
        } else {
            lst.update(a[i], m);
        }
    }
    cout << lst.get(0, m) << endl;
}

signed main() {
    int test = 1;
    // cin >> test;
    while (test--) {
        Solve();
    }
}