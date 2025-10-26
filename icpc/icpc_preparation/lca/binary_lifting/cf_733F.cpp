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

vector < ll > ds;

vector < vector < ll > > adj, up, ma, idx, mai;

ll getP(ll k) {
    if (ds[k] != k) {

        ll p = getP(ds[k]);
        ds[k] = p;
    }
    return ds[k];
}
void join(ll x, ll y) {
    ll p = getP(x);
    ll q = getP(y);
    if (p != q) {
        ds[p] = q;
    }
}

ll n, le, timer;
vector < ll > tin, tout, cost;



void dfs(ll k, ll p, ll id) {
    test << "dfs" _ k _ p _ id _ endl;
    tin[k] = timer++;
    up[k][0] = p;
    ma[k][0] = cost[id];
    mai[k][0] = id;
    ll i;
    
    for (i = 1;i < le;i++) {
        test<<i _ k <<endl;
        up[k][i] = up[up[k][i - 1]][i - 1];
        if (ma[k][i - 1] > ma[up[k][i - 1]][i - 1]) {
            ma[k][i] = ma[k][i - 1];
            mai[k][i] = mai[k][i - 1];
        } else {
            ma[k][i] = ma[up[k][i - 1]][i - 1];
            mai[k][i] = mai[up[k][i - 1]][i - 1];
        }
    }
    i = 0;
    for (ll to : adj[k]) {
        i++;
        if (to != p) {
            test<< to _ k _ i<<endl;
            dfs(to, k, cost[idx[k][i]]);
        }
    }
    tout[k] = timer++;
}

void preprocess() {
    le = ceil(log2(n));
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vector < ll >(le));
    ma.assign(n, vector < ll >(le));
    mai.assign(n, vector < ll >(le));

    dfs(0, 0, cost.size()-1);
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair < ll, ll >  get(ll u1, ll v1) {

    test << "come: " _ u1 _ v1 << endl;
    ll res = 0, i, j, u, v, resi;
    u = u1;
    v = v1;
    if (!isA(u, v)) {
        for (i = le - 1;i >= 0;i--) {
            if (!isA(up[u][i], v)) {
                if (ma[u][i] > res) {
                    res = ma[u][i];
                    resi = mai[u][i];
                }
                u = up[u][i];
            }
        }
        if (ma[u][0] > res) {
            res = ma[u][0];
            resi = mai[u][0];
        }
    }
    u = v1;
    v = u1;
    if (!isA(u, v)) {
        for (i = le - 1;i >= 0;i--) {
            if (!isA(up[u][i], v)) {
                if (ma[u][i] > res) {
                    res = ma[u][i];
                    resi = mai[u][i];
                }
                u = up[u][i];
            }
        }
        if (ma[u][0] > res) {
            res = ma[u][0];
            resi = mai[u][0];
        }
    }
    return { res, resi };
}

int main() {
    ll m, i, j, k, s, u, v, cnt, mc = INT_MAX, res = 0, sum = 0, add = 0, mci, mcw;
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    cost.clear();
    cost.resize(m + 1);
    idx.clear();
    idx.resize(n);
    pair < ll, ll > pr;
    vector < ll > vis(m, 0);
    vector < pair < ll, ll > > vc(m), c(m), w(m);
    for (i = 0;i < m;i++) {
        cin >> cost[i];
        c[i] = { cost[i], i };
    }
    cost[m] = 0;
    for (i = 0;i < m;i++) {
        cin >> k;
        w[i] = { k, i };
    }

    ds.clear();
    ds.resize(n);
    for (i = 0;i < n;i++) {
        ds[i] = i;
    }
    for (i = 0;i < m;i++) {
        cin >> u >> v;
        vc[i] = { u - 1, v - 1 };
    }
    cin >> s;
    sort(ALL(c));
    cnt = 1;
    i = 0;
    while (cnt < n) {
        j = c[i].ss;
        if (getP(vc[j].ff) != getP(vc[j].ss)) {
            join(vc[j].ff, vc[j].ss);
            cnt++;
            vis[j] = 1;
            test << "chosen" _ vc[j].ff _ vc[j].ss _ c[i].ss _ cost[c[i].ss] _ w[j].ff << endl;
            adj[vc[j].ff].pb(vc[j].ss);
            adj[vc[j].ss].pb(vc[j].ff);
            idx[vc[j].ff].pb(c[i].ss);
            idx[vc[j].ss].pb(c[i].ss);
            res += c[i].ff;
            if (mc > w[j].ff) {
                mc = w[i].ff;
                mci = j;
            }
        }
        i++;
    }
    preprocess();
    ll added = -1, subbed = -1, subw;
    add = -(s / mc);
    test << mc << endl;
    sort(ALL(w));
    for (i = 0;i < m;i++) {
        j = w[i].ss;
        if (!vis[j]) {
            pr = get(vc[j].ff, vc[j].ss);
            test << "get: " _ pr.ff _ pr.ss << endl;
            if (add > cost[i] - pr.ff - (s / w[i].ff)) {
                added = j;
                subbed = pr.ss;
                add = cost[j] - pr.ff - (s / w[i].ff);
                // cost[j] -= (s / w[i].ff) * w[i].ff;
                subw = w[i].ff;
            }
        }

    }
    test << "res: " _ res _ add _ mc _ mci << endl;
    cout << res + add << endl;
    if (added != -1) {
        vis[added] = 1;
        vis[subbed] = 0;
        cost[subbed] -= (s / subw) * subw;
    } else {
        cost[mci] -= (s / mc) * mc;
    }
    for (i = 0;i < m;i++) {
        if (vis[i]) {
            cout << i _ cost[i] << endl;
        }
    }
    return 0;
}