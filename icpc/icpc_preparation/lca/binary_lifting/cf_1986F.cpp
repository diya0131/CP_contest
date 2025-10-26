#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define SORTI(arr, arri) sort(ALL(arri), [&](const int &a, const int &b){ return (arr)[a] < (arr)[b]; })
#define test if(te) cout
#define _ <<" "<<
#define ff first
#define ss second

using namespace std;

const bool te = false;

vector < ll > dsu;
vector < vector < ll > > adj;

ll par(ll k) {
    if (dsu[k] != k) {
        ll p = par(dsu[k]);
        dsu[k] = p;
    }
    return dsu[k];
}

vector < ll > tin, tout, mark, he;
ll n, le, timer;
vector < vector < ll > > up;

void dfs(ll k, ll p, ll lvl) {
    test << "dfs" _ k _ p << endl;
    mark[k] = lvl;
    he[k] = lvl;
    tin[k] = timer++;
    up[k][0] = p;
    for (ll i = 1;i < le;i++) up[k][i] = up[up[k][i - 1]][i - 1];
    for (ll to : adj[k]) {
        if (to != p) dfs(to, k, lvl + 1);
    }
    tout[k] = timer++;
}

void preprocess() {
    test << "preprocess\n";
    tin.resize(n);
    mark.resize(n);
    he.resize(n);
    tout.resize(n);
    timer = 0;
    le = ceil(log2(n)) + 1;
    up.assign(n, vector < ll >(le));
    dfs(0, 0, 0);
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll get(ll u, ll v) {
    if (isA(u, v)) return u;
    if (isA(v, u)) return v;
    for (ll i = le - 1;i >= 0;i--) {
        if (!isA(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
ll res;
pair < ll, ll> count(ll k, ll p) {
    ll all = 1, mr = mark[k];
    pair < ll, ll > pr;
    for (ll to : adj[k]) {
        if (to != p) {
            pr = count(to, k);
            all += pr.ff;
            mr = min(mr, pr.ss);
        }
    }
    if (mr >= he[k]) {
        test << n _ all _(n - all) * all << endl;
        res = max(res, (n - all) * all);
    }
    return { all, mr };
}



void solve() {
    ll m, i, j, k, s, u, v, p1, p2;
    cin >> n >> m;
    dsu.resize(n);
    adj.clear();
    adj.resize(n);
    for (i = 0;i < n;i++) dsu[i] = i;
    vector < pair < ll, ll > > vc(m);
    j = 0;
    for (i = 0;i < m;i++) {
        cin >> u >> v;
        u--; v--;
        p1 = par(u);
        p2 = par(v);
        if (p1 != p2) {
            adj[u].pb(v);
            adj[v].pb(u);
            test << "join" _ u _ v << endl;
            dsu[p1] = p2;
        } else {
            vc[j] = { u, v };
            j++;
        }
    }
    preprocess();
    for (i = 0;i < j;i++) {

        k = get(vc[i].ff, vc[i].ss);
        mark[vc[i].ff] = min(mark[vc[i].ff], he[k]);
        mark[vc[i].ss] = min(mark[vc[i].ss], he[k]);

    }
    res = 0;
    count(0, 0);
    test << n _ res << endl;
    cout << (n - 1) * n / 2 - res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}