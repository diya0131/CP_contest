#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define PLL pair < ll, ll >
#define _ <<" "<<
#define ff first
#define ss second
using namespace std;

const bool te = false;

vector < vector < pair < ll, ll > > > path;

vector < vector < ll > > up, mi, ma;
vector < ll > tin, tout;
ll timer, le, n;

void dfs(ll k, ll p, ll w) {
    tin[k] = timer++;
    up[k][0] = p;
    mi[k][0] = w;
    ma[k][0] = w;
    for (int i = 1; i <= le; i++) {
        up[k][i] = up[up[k][i - 1]][i - 1];
        mi[k][i] = min(mi[k][i - 1], mi[up[k][i - 1]][i - 1]);
        ma[k][i] = max(ma[k][i - 1], ma[up[k][i - 1]][i - 1]);
    }
    for (auto u : path[k]) {
        if (u.ff != p)
            dfs(u.ff, k, u.ss);
    }

    tout[k] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    ll a;
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = le; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

pair < ll, ll > get(ll u1, ll v1) {
    ll a, u = u1, v = v1, resmi = INT_MAX, resma = 0;
    if(!is_ancestor(u, v)){
        for (int i = le; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                resmi = min(resmi, mi[u][i]);
                resma = max(resma, ma[u][i]);
                u = up[u][i];
            }
        }
        resmi = min(resmi, mi[u][0]);
        resma = max(resma, ma[u][0]);
    }
    u = v1;
    v = u1;
    if(!is_ancestor(u, v)){
        for (int i = le; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                resmi = min(resmi, mi[u][i]);
                resma = max(resma, ma[u][i]);
                u = up[u][i];
            }
        }
        resmi = min(resmi, mi[u][0]);
        resma = max(resma, ma[u][0]);
    }
    return {resmi, resma};
}

void preprocess() {
    
    tin.resize(n);
    tout.resize(n);
    le = ceil(log2(n));
    timer = 0;
    up.assign(n, vector<ll>(le + 1));
    mi.assign(n, vector<ll>(le + 1));
    ma.assign(n, vector<ll>(le + 1));
    dfs(0, 0, 0);
}


int main() {
    ll i, j, q, u, v, t;
    pair < ll, ll > pr;
    cin >> n;
    path.resize(n);
    for (i = 1;i < n;i++) {
        cin >> u >> v >> t;
        u--; v--;
        path[u].pb({ v, t });
        path[v].pb({ u, t });
    }
    preprocess();
    cin>>q;
    while(q--){
        cin>>u>>v;
        pr = get(u-1, v-1);
        cout<<pr.ff _ pr.ss<<endl;
    }
}