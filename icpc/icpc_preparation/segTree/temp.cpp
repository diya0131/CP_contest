// https://codeforces.com/contest/446/problem/C

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

vector<int> fib, pre;

int add(int x, int y) {
    return (x + y) % MOD;
}
int sub(int x, int y) {
    return ((x - y) % MOD + MOD) % MOD;
}
int mult(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}
PII add_pair(PII x, PII y) {
    return { add(x.first, y.first), add(x.second, y.second) };
}

class LazySegmentTree {
public:
    vector<int> tree;
    vector<PII> lazy;
    vector<int> arr;
    int n;

    LazySegmentTree(int n, vector<int>& a) : n(n), arr(a) {
        tree = vector<int>(4 * n, 0);
        lazy = vector<PII>(4 * n, { 0, 0 });
        build(0, n - 1, 1);
    }

    void build(int l, int r, int v) {
        if (l == r) {
            tree[v] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * v);
        build(m + 1, r, 2 * v + 1);
        tree[v] = add(tree[2 * v], tree[2 * v + 1]);
    }

    void push(int v, int l, int r) {
        if (l == r ) {
            return;
        }
        int m = (l + r) / 2;
        auto [a, b] = lazy[v];
        if(a==0 && b==0) return;
        // if (l + 1 == r) {
        //     lazy[2 * v].first = add(lazy[2 * v].first, a);
        //     lazy[2 * v + 1].first = add(lazy[2 * v + 1].first, b);
        //     tree[2 * v] = add(tree[2 * v], a);
        //     tree[2 * v + 1] = add(tree[2 * v + 1], b);
        //     lazy[v]={0, 0};
        //     return;
        // }
        
        int ma = add(mult(fib[m - l + 1], a), mult((fib[m - l + 2] - 1),b));
        int mb = add(mult(fib[m - l + 2], a), mult((fib[m - l + 3] - 1),b));
        lazy[2 * v] = add_pair(lazy[2 * v], { a, b });
        lazy[2 * v + 1] = add_pair(lazy[2 * v + 1], { ma, mb });
        cout<<m _ fib[m-l+1] _ fib[m - l + 2]<<endl;
        cout<< a _ b _ ma _ mb << endl;
        cout<<"push" _ l _ r _ mult(pre[m - l + 1], a)+ mult((pre[m - l + 2] - 1), b) _ mult(pre[r - m], ma)+ mult((pre[r - m + 1] - 1), mb)<<endl;
        tree[2 * v] = add(tree[2 * v], add(mult(pre[m - l + 1], a), mult((pre[m - l + 2] - 1), b)));
        tree[2 * v + 1] = add(tree[2 * v + 1], add(mult(pre[r - m], ma), mult((pre[r - m + 1] - 1),mb)));
        lazy[v] = { 0, 0 };
    }

    void update(int l, int r) {
        update(0, n - 1, 1, l, r, l);
    }

    void update(int tl, int tr, int v, int l, int r, int L) {
        if (l > r) {
            return;
        }
        if (tl == l && tr == r) {
            lazy[v] = add_pair(lazy[v], { fib[l - L + 2], fib[l - L + 3] });
            ll a = fib[l - L + 2];
            ll b = fib[l - L + 3];
            cout<<"last add" _ tl _ tr _ add(mult(pre[tr - tl + 1], a), mult((pre[tr - tl + 2] - 1), b)) _ tree[v]<<endl;
            tree[v] = add(tree[v], add(mult(pre[tr - tl + 1], a), mult((pre[tr - tl + 2] - 1), b)));
            return;
        }
        push(v, tl, tr);
        int m = (tl + tr) / 2;
        update(tl, m, 2 * v, l, min(m, r), L);
        update(m + 1, tr, 2 * v + 1, max(m + 1, l), r, L);
        tree[v] = add(tree[2 * v], tree[2 * v + 1]);
    }

    int get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }

    int get(int l, int r, int tl, int tr, int v) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            // cout<<"get last" _ tl _ tr<<endl;
            return tree[v];
        }
        push(v, tl, tr);
        int m = (tl + tr) / 2;
        return add(get(l, min(m, r), tl, m, 2 * v), get(max(l, m + 1), r, m + 1, tr, 2 * v + 1));
    }

    void print() {
        for (int i = 0; i < 4 * n; i++) {
            cout << tree[i] << " \n"[i == 4 * n - 1];
        }
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    fib = vector<int>(n + 10, 0);
    pre = vector<int>(n + 10, 0);
    fib[0] = 1;
    fib[1] = 0;
    for (int i = 2; i <= n + 5; i++) {
        fib[i] = add(fib[i - 1], fib[i - 2]);
    }
    for (int i = 0; i <= n + 5; i++) {
        pre[i + 1] = add(pre[i], fib[i]);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int type, l, r;
    LazySegmentTree lst(n, a);
    while (q--) {
        cin >> type >> l >> r;
        l--; r--;
        if (type == 1) {
            lst.update(l, r);
        } else {
            cout << lst.get(l, r) << endl;
        }
        // lst.print();
    }
}