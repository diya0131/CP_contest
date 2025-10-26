// https://www.codechef.com/problems/TALCA

#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define PLL pair < ll, ll >
#define _ <<" "<<

using namespace std;

const bool te = false;

struct LCA {
    vector < ll > he, fr, eu, st;
    ll n, m;
    LCA(vector < vector < ll > >& path, ll root) {
        n = path.size();
        fr.resize(n);
        he.resize(n);
        dfs(path, root, -1, 0);

        m = eu.size();
        for (int num : eu) {
            test << num << " ";
        }
        test << endl;
        for (int i = 0;i < n;i++) {
            test << he[i] << " \n"[i == n - 1];
        }
        st.resize(4 * m);
        build(1, 0, m);
    }

    void dfs(vector < vector < ll > >& path, ll k, ll p, ll lvl) {
        he[k] = lvl;
        fr[k] = eu.size();
        eu.pb(k);
        for (int to : path[k]) {
            if (to != p) {
                dfs(path, to, k, lvl + 1);
                eu.pb(k);
            }
        }
    }

    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            st[v] = tl;
            return;
        }
        ll tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        if (he[eu[st[2 * v]] < he[eu[st[2 * v + 1]]]]) st[v] = st[2 * v];
        else st[v] = st[2 * v + 1];
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return -1;
        if (tl == l && r == tr) {
            return st[v];
        }
        ll tm = (tl + tr) / 2;
        ll le = query(2 * v, tl, tm, l, min(r, tm));
        ll ri = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        test << tl _ tr _ tm _ le _ ri << endl;
        if (le == -1) return ri;
        if (ri == -1) return le;
        if (he[eu[le]] < he[eu[ri]]) return le;
        return ri;
    }

    ll lca(ll le, ll ri) {
        le = fr[le];
        ri = fr[ri];
        if (le > ri) swap(le, ri);
        test << le _ ri << endl;
        return eu[query(1, 0, m - 1, le, ri)];
    }
};

int main() {
    ll n, i, j, m, q, u, v;
    cin >> n;
    vector < vector < ll > > path(n);
    for (i = 1;i < n;i++) {
        cin >> u >> v;
        u--;
        v--;
        path[v].pb(u);
        path[u].pb(v);
    }
    vector < LCA > vc;
    for (i = 0;i < n;i++) {
        vc.pb(LCA(path, i));
    }
    cin >> q;
    while (q--) {
        cin >> m >> u >> v;
        cout << vc[m - 1].lca(u - 1, v - 1) + 1 << endl;
    }
    return 0;
}