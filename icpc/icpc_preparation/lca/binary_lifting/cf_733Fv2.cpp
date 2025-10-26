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

void dfs(ll k, ll p, ll idx) {
    tin[k] = timer++;
    ma[k][0] = idx;
    up[k][0] = p;
    for (int i = 1;i < le;i++) {
        up[k][i] = up[up[k][i - 1]][i - 1];
        if (w[ma[k][i - 1]] < w[ma[up[k][i - 1]][i - 1]]) {
            ma[k][i] = ma[up[k][i - 1]][i - 1];
        } else {
            ma[k][i] = ma[k][i - 1];
        }
    }
    for (auto to : adj[k]) {
        if (to.ff != p) dfs(to.ff, k, to.ss);
    }
    tout[k] = timer++;
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll get(ll u1, ll v1) {
    ll u, v, res = 0, resi;
    u = u1; v = v1;
    if (!isA(u, v)) {
        for (int i = le - 1;i >= 0;i--) {
            if (!isA(up[u][i], v)) {
                if (res < w[ma[u][i]]) {
                    resi = ma[u][i];
                    res = w[resi];
                }
                u = up[u][i];
            }
        }
        if (res < w[ma[u][0]]) {
            resi = ma[u][0];
            res = w[resi];
        }
    }
    u = v1; v = u1;
    if (!isA(u, v)) {
        for (int i = le - 1;i >= 0;i--) {
            if (!isA(up[u][i], v)) {
                if (res < w[ma[u][i]]) {
                    resi = ma[u][i];
                    res = w[resi];
                }
                u = up[u][i];
            }
        }
        if (res < w[ma[u][0]]) {
            resi = ma[u][0];
            res = w[resi];
        }
    }
    return resi;
}

void preprocess() {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    le = ceil(log2(n));
    up.assign(n, vector < ll >(le));
    ma.assign(n, vector < ll >(le));
    dfs(0, 0, 0);
}



int main() {
    ll i, j, s, res, m, cnt = 1, u, v, p1, p2, cm = INT_MAX, cmi, k, add;
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
    cin >> s;
    SORTI(w, wi);
    SORTI(c, ci);

    for (i = 0;i < n;i++) {
        dsu[i] = i;
    }
    res = 0;
    for (i = 0;i < m;i++) {
        if (cnt == n) break;
        u = vc[wi[i]].ff;
        v = vc[wi[i]].ss;
        p1 = par(u);
        p2 = par(v);
        if (p1 != p2) {
            cnt++;
            res += w[wi[i]];
            vis[wi[i]] = 1;
            dsu[p1] = p2;
            adj[u].pb({ v, wi[i] });
            adj[v].pb({ u, wi[i] });
            if (c[wi[i]] < cm) {
                cmi = wi[i];
                cm = c[cmi];
            }
        }
    }

    add = -(s / cm);

    preprocess();

    ll added = -1, subbed;

    for (i = 0;i < m;i++) {
        j = ci[i];
        if (c[j] >= cm) break;
        k = get(vc[j].ff, vc[j].ss);
        if (add > w[j] - w[k] - s / c[j]) {
            added = j;
            subbed = k;
            add = w[j] - w[k] - s / c[j];
        }
    }
    if (added == -1) {
        w[cmi] -= s / cm;
    } else {
        vis[subbed] = 0;
        vis[added] = 1;
        w[added] -= s / c[added];
    }
    cout<<res+add<<endl;
    for(i=0;i<m;i++){
        if(vis[i]){
            cout<<i+1 _ w[i]<<endl;
        }
    }

    return 0;
}