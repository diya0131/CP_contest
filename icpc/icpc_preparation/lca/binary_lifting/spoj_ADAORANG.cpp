#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define _ <<" "<<
#define ff first
#define ss second

using namespace std;

const ll sz = 250;
vector < bitset<sz> > xr;
vector < ll > a, tin, tout;
ll n, m, timer;
vector < vector < ll > > up, path;

void dfs(ll k, ll p) {
    tin[k] = timer++;
    up[k][0] = p;
    ll i, j;
    xr[k].set(a[k]);
    for (i = 1;i < m;i++) {
        up[k][i] = up[up[k][i - 1]][i - 1];
    }
    for (ll to : path[k]) {
        if (to != p) {
            dfs(to, k);
            xr[k] = xr[k] | xr[to];
        }
    }
    tout[k] = timer++;
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (isA(u, v)) return u;
    if (isA(v, u)) return v;
    for (int i = m - 1;i >= 0;i--) {
        if (!isA(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll rt) {
   
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    m = ceil(log2(n));
    up.assign(n, vector < ll >(m));
    xr.assign(n, bitset<sz>(0));
    dfs(rt, rt);
}

void solve() {
    ll i, j, s, k, le, root, q, u, v, sum, t;
    cin >> n >> q >> root;
    path.resize(n);
    a.resize(n);
    for (i = 0;i < n;i++) {
        cin >> k;
        a[i] = k - 1;
    }
    for (i = 1;i < n;i++) {
        cin >> u >> v;
        path[u].pb(v);
        path[v].pb(u);
    }
    preprocess(root);
    while (q--) {
        cin >> u >> v;
        k = lca(u, v);
        cout << xr[k].count() << endl;
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}