#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

ll cnt;

vector < ll > posp, posl, posr, isl;
vector < bool > is;

void dfs(ll k, ll l, ll r) {
    if (l == r) return;
    posp[l + 1] = k;
    posp[(l + r) / 2 + 1] = k;
    posl[k] = l + 1;
    posr[k] = (l + r) / 2 + 1;
    dfs(l + 1, l + 1, (l + r) / 2);
    dfs((l + r) / 2 + 1, (l + r) / 2 + 1, r);
}

void check(vector < ll >& p, vector < ll >& par, ll k) {
    if (k == 0) return;
    test << "ch" _ k << endl;
    ll i;
    bool can = true;
    if (p[k] != 1) {
        if (par[p[k]] != p[posp[k]]) can = false;
    } else {
        if (k != 1) can = false;
    }
    test << can << endl;

    test << posl[k] _(p[k] != par[p[posl[k]]]) _(p[k] != par[p[posr[k]]]) << endl;
    if (!isl[p[k]] && posl[k] == 0) can = false;
    if (posl[k] != 0 && p[k] != par[p[posl[k]]]) can = false;
    if (posr[k] != 0 && p[k] != par[p[posr[k]]]) can = false;

    test << can _ cnt _ k _ is[k] << endl;
    if (can) {
        if (!is[k]) {
            cnt++;
        }
    } else {
        if (is[k]) {
            cnt--;
        }
    }
    is[k] = can;
    test << can _ cnt << endl;
}

void solve() {
    ll n, m, k, i, j, x, y, q, t;
    cin >> n >> q;
    bool can;
    vector < ll > ppar(n + 1, 0), par(n + 1, 0);
    isl.resize(n + 1, 1);
    posp.resize(n + 1, 0);
    posl.resize(n + 1, 0);
    posr.resize(n + 1, 0);
    dfs(1, 1, n);
    // for(i=1;i<=n;i++){
    //     cout<<posp[i]<<" \n"[i==n];
    // }
    //  for(i=1;i<=n;i++){
    //     cout<<posl[i]<<" \n"[i==n];
    // }
    //  for(i=1;i<=n;i++){
    //     cout<<posr[i]<<" \n"[i==n];
    // }
    for (i = 2;i <= n;i++) {
        cin >> k;

        ppar[i] = k;
    }
    vector < ll > p(n + 1);
    is.resize(n + 1, 0);
    for (i = 1;i <= n;i++) {
        cin >> p[i];

    }
    for (i = 1;i <= n;i++) {
        if (ppar[i] != 0) {
            par[p[i]] = p[ppar[i]];
            isl[p[ppar[i]]] = 0;
        }

        // cout<<p[i] _ par[p[i]]<<endl;
    }
    // for (i = 1;i <= n;i++) {
    //     cout << ppar[i] << " \n"[i == n];
    // }
    // for (i = 1;i <= n;i++) {
    //     cout << isl[i] << " \n"[i == n];
    // }
    cnt = 0;
    for (i = 1;i <= n;i++) {
        check(p, par, i);
    }
    test << cnt << endl;
    while (q--) {
        cin >> x >> y;
        t = p[x];
        p[x] = p[y];
        p[y] = t;
        check(p, par, posp[x]);
        check(p, par, x);

        test << "pos" _ x _ posl[x] _ posr[x] << endl;
        check(p, par, posl[x]);
        check(p, par, posr[x]);

        check(p, par, posp[y]);
        check(p, par, y);

        test << "pos" _ y _ posl[y] _ posr[y] << endl;
        check(p, par, posl[y]);
        check(p, par, posr[y]);

        if (cnt == n) {
            cout << "YES\n";
        } else cout << "NO\n";
    }

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}