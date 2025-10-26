#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ALL(a) a.begin(), a.end()
// #define SORTI(arr, arri) sort(ALL(arri), [&](const int &a, const int &b){ return (arr)[a] < (arr)[b]; })
#define test if(te) cout
#define _ <<" "<<
#define ff first
#define ss second

using namespace std;

const bool te = true;

vector < ll > w, c, wi, ci, dsu;

ll par(ll k) {
    if (dsu[k] != k) {
        ll p = par(dsu[k]);
        dsu[k] = p;
    }
    return dsu[k];
}

vector < vector < pair < ll, ll > > > adj;

vector < ll > tin, tout;
ll n, timer, le;
vector < vector < ll > > up, ma;

void preprocess() {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    le = ceil(log2(n));
    up.assign(n, vector < ll >(le));
}



int main() {
    ll i, s, res, m, cnt = 1, u, v, p1, p2;
    cin >> n >> m;
    w.resize(m);
    c.resize(m);
    wi.resize(m);
    ci.resize(m);
    dsu.resize(n);
    adj.resize(n);
    vector < pair < ll, ll > > vc(m);
    vector < bool > vis(m, 0);
    for (i = 0;i < m;i++) {
        wi[i] = i;
        ci[i] = i;
        cin >> w[i];
    }
    for (i = 0;i < m;i++) cin >> c[i];
    for (i = 0;i < m;i++) {
        cin >> u >> v;
        vc[i] = { u - 1, v - 1 };
    }
    SORTI(w, wi);
    SORTI(c, ci);

    for (i = 0;i < n;i++) {
        dsu[i] = i;
    }

    for (i = 0;i < m;i++) {
        if (cnt == n) break;
        u = vc[wi[i]].ff;
        v = vc[wi[i]].ss;
        p1 = par(u);
        p2 = par(v);
        if (p1 != p2) {
            cnt++;
            vis[wi[i]] = 1;
            dsu[p1] = p2;
            adj[u].pb({ v, wi[i] });
            adj[v].pb({ u, wi[i] });
        }
    }

    preprocess();

    return 0;
}