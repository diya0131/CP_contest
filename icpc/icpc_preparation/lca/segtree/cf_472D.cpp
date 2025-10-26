
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

const ll N = 4000;

vector < ll > len;
vector < vector < ll > > w;

struct LCA {
    vector < ll > he, eu, st, fr;

    ll n, m;
    LCA(vector < vector < ll > >& path) {
        n = path.size();
        he.resize(n);
        fr.resize(n);
        dfs(0, -1, 0, 0, path);
        eu.reserve(2 * n);
        m = eu.size();
        st.resize(4 * m);
        build(1, 0, m - 1);
    }

    void dfs(ll k, ll p, ll lvl, ll leng, vector < vector < ll > >& path) {
        test<<"dfs" _ k _ lvl<<endl;
        fr[k] = eu.size();
        eu.pb(k);
        he[k] = lvl;
        len[k] = leng;
        for (int d : path[k]) {
            if(d!=p){
                dfs(d, k, lvl + 1, leng + w[k][d], path);
                eu.pb(k);
            }
        }
    }
    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            st[v] = eu[tl];
            return;
        }
        ll tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        if (he[st[2 * v]] < he[st[2 * v + 1]]) st[v] = st[2 * v];
        else st[v] = st[2 * v + 1];
    }
    ll get(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return -1;
        if (tl == l && tr == r) return st[v];
        ll tm = (tl + tr) / 2;
        ll lv = get(2 * v, tl, tm, l, min(r, tm));
        ll rv = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        if (lv == -1 || rv == -1) return rv + lv + 1;
        if (he[lv] < he[rv]) return lv;
        else return rv;
    }
    ll lca(ll l, ll r) {
        if (fr[l] > fr[r]) swap(l, r);
        return get(1, 0, m - 1, fr[l], fr[r]);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, i, j, k, s, d, p;
    cin >> n;
    w.clear();
    w.resize(n, vector < ll >(n));
    vector < pair < ll, ll > > vc(n);
    for (j = 0;j < n;j++) {
        cin >> w[0][j];
        vc[j] = { w[0][j], j };
    }
    for (i = 1;i < n;i++) {
        for (j = 0;j < n;j++) {
            cin >> w[i][j];
        }
    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            if (i == j) {
                if (w[i][j] != 0) {
                    cout << "NO\n";
                    return 0;
                }
            } else {
                if (w[i][j] != w[j][i] || w[i][j] == 0) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    vector < vector < ll > > path(n);
    sort(ALL(vc));
    for (i = 1;i < n;i++) {
        d = w[vc[i].ss][0];
        bool child = true;
        for (j = i - 1;j >= 0;j--) {
            if (d == w[vc[i].ss][vc[j].ss] + w[vc[j].ss][0]) {
                child = 0;
                test << "drwen" _ vc[i].ss _ vc[j].ss _ d _ w[vc[i].ss][vc[j].ss] _ w[vc[j].ss][0] << endl;
                path[vc[j].ss].pb(vc[i].ss);
                break;
            }
        }
        if (child) {
            path[0].pb(vc[i].ss);
        }
    }
    test << "tree\n";
    for (i = 0;i < n;i++) {
        for (int pa : path[i]) {
            test << pa << " ";
        }
        test << endl;
    }
    len.resize(n);
    LCA lca(path);
    for (i = 0;i < n;i++) {
        test << len[i] << " ";
    }
    test << endl;

    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            p = lca.lca(i, j);
            test << "lca" _ p _ i _ j << endl;
            if (w[i][j] != len[i] + len[j] - 2 * len[p]) {
                test << i _ j _ p << endl;
                cout << "NO\n";
                return 0;
            }

        }
    }
    cout << "YES\n";
}