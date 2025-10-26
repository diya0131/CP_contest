#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define _ <<" "<<
#define ff first
#define ss second

using namespace std;

const bool te = true;

vector < ll > tin, tout;
vector < vector < ll > > up, path;

ll n, m, timer;

void dfs(ll k, ll p) {
    // test<<k _ p<<endl;
    tin[k] = timer++;
    up[k][0] = p;
    for (ll l = 1;l < m;l++) {
        up[k][l] = up[up[k][l - 1]][l - 1];
    }
    for (ll to : path[k]) {
        if (to != p) {
            dfs(to, k);
        }
    }
    tout[k] = timer++;
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    m = ceil(log2(n));
    up.assign(n, vector < ll >(m));
    dfs(root, root);
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (isA(u, v)) return u;
    if (isA(v, u)) return v;
    for (int i = m - 1;i >= 0;i--) {
        if (!isA(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}


int main() {
    ll i, j, s, k, t, u, v, q;
    cin >> n;
    path.resize(n);
    for (i = 0;i < n;i++) {
        cin >> k;
        while (k--) {
            cin >> t;
            path[i].pb(t);
        }
    }
    preprocess(0);
    cin >> q;
    while (q--) {
        cin >> u >> v;
        cout << lca(u , v ) << endl;
    }
}