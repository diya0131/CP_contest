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
const int MOD = 998244353;

int add(int x, int y) {
    x %= MOD; y %= MOD;
    return (x + y + MOD) % MOD;
}
int sub(int x, int y) {
    x %= MOD; y %= MOD;
    return (x - y + MOD) % MOD;
}
int mult(int x, int y) {
    x %= MOD; y %= MOD;
    return (x * y%MOD + MOD) % MOD;
}
int pow(int x, int n) {
    if (n == 0) return 1;
    int sub = pow(x, n / 2);
    int ret = mult(sub, sub);;
    if (n & 1) {
        ret = mult(ret, x);
    }
    return ret;
}
int divide(int x, int y) {
    return mult(x, pow(y, MOD - 2));
}

vector<vector<int>> child, anc, anc_val;
vector<int> tin, tout, val, mul;
int timer;

void build(int cur) {
    tin[cur] = ++timer;
    for (int to : child[cur]) {
        build(to);
        val[cur] = mult(val[cur], (val[to] + 1));
    }
    tout[cur] = ++timer;
}

void dfs(int cur) {
    anc_val[cur][0] = val[cur];
    for (int i = 1; i < 20; i++) {
        anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
        anc_val[cur][i] = add(anc_val[cur][i - 1], anc_val[anc[cur][i - 1]][i - 1]);
    }
    for (int to : child[cur]) {
        mul[to] = mult((mul[cur] + 1), divide(val[cur], (val[to] + 1)));
    }
    for (int to : child[cur]) {
        dfs(to);
    }
}

bool is_ancestor(int x, int y) {
    return (tin[x] <= tin[y]) && (tout[x] >= tout[y]);
}

int lca(int x, int y) {
    if (is_ancestor(x, y)) return x;
    if (is_ancestor(y, x)) return y;
    for (int i = 19; i >= 0; i--) {
        if (!is_ancestor(anc[x][i], y)) {
            x = anc[x][i];
        }
    }
    return anc[x][0];
}

int get(int node, int ancestor) {
    if (node == ancestor) return 0;
    for (int i = 19; i >= 0; i--) {
        if (!is_ancestor(anc[node][i], ancestor)) {
            return add(anc_val[node][i], get(anc[node][i], ancestor));
        }
    }
    return val[node];
}

void init(int n) {
    timer = 0;
    child.assign(n, {});
    val.assign(n, 1);
    mul.assign(n, 0);
    tin.assign(n, 0);
    tout.assign(n, 0);
    anc.assign(n, vector<int>(20, 0));
    anc_val.assign(n, vector<int>(20, 0));
}

void Solve(int TEST) {
    int n, q;
    cin >> n >> q;
    init(n);

    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        child[p[i]].push_back(i);
        anc[i][0] = p[i];
    }
    build(0);
    dfs(0);
    int u, v;
    while (q--) {
        cin >> u >> v;
        u--; v--;
        int an = lca(u, v);
        int ret = val[an];
        ret = add(ret, get(u, an));
        ret = add(ret, get(v, an));
        ret = add(ret, mult(val[an], mul[an]));
        print(an, get(u, an), get(v, an));
        cout << (ret%MOD+MOD)%MOD << endl;
    }
}

signed main() {
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        Solve(i);
    }
}
