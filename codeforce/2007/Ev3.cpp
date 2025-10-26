#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

ll timer, w;
vector < set < ll > > adj;
vector < pair < ll, ll > > t;
vector < ll > dn, change, all;

pair < ll, ll > dfsdone(ll k) {
    ll mx = 0, s = 0;
    set < ll >::iterator it;
    pair < ll, ll > pr;
    pair < ll, ll > p = { 0, 0 };
    if (adj[k].size() == 0) {
        return t[k];
    }

    // if (p.ss.ff < t[*it].ff) {
    //     p.ss = t[*it];
    // }
    // // cout << p.ff _ p.ss.ff _ p.ss.ss << endl;

    // change[p.ss.ff] += (w - all[p.ss.ff - 1] + p.ff - p.ss.ss) - (p.ff);
    // p = dfsdone(*it);
    // it++;
    it = adj[k].begin();
    pr = t[*it];

    dn[pr.ff]++;
    change[pr.ff] += w - all[pr.ff - 1] - pr.ss;
    test << "change" _ pr.ff _(w - all[pr.ff - 1] - pr.ss) _ all[pr.ff - 1] _(pr.ss) << endl;

    for (it = adj[k].begin();it != adj[k].end();it++) {
        // cout << k _ p.ff _ p.ss.ff _ p.ss.ss << endl;
        // cout << t[*it].ff _ t[*it].ss << endl;
        // if (p.ss.ff < t[*it].ff) {
        //     p.ss = t[*it];
        // }




        if (it != adj[k].begin()) {
            if (p.ff < t[*it].ff) {
                pr = t[*it];
            } else {
                pr = p;
            }
            dn[pr.ff]++;
            change[pr.ff] += w - all[pr.ff - 1] - pr.ss;
            test << "change" _ pr.ff _(w - all[pr.ff - 1] - pr.ss) _ all[pr.ff - 1] _(pr.ss) << endl;
        }


        p = dfsdone(*it);
        test << "re" _ all[p.ff - 1] _ p.ff _ p.ss << endl;
    }
    test << k _ t[k].ff _ t[k].ss << endl;

    if (p.ff < t[k].ff) {
        return t[k];
    }
    return p;
}


void solve() {
    ll n, i, j, m, k, s, x, y;
    pair < ll, ll > p;
    cin >> n >> w;
    adj.clear();
    adj.resize(n);
    t.assign(n, { 0, 0 });
    dn.assign(n, 0);
    change.assign(n, 0);
    all.assign(n, 0);
    for (i = 1;i < n;i++) {
        cin >> k;
        // adj[i].insert(k-1);
        adj[k - 1].insert(i);
    }
    vector < ll > tm(n - 1);
    s = 0;
    for (i = 1;i < n;i++) {
        cin >> x >> y;
        tm[i - 1] = y;
        s += y;
        all[i] = s;
        t[x - 1] = { i, y };
    }
    p = dfsdone(0);
    test << p.ff _ p.ff _ p.ss _ all[p.ff - 1] << endl;
    dn[p.ff]++;
    change[p.ff] += (w - all[p.ff - 1] - p.ss);

    ll res = n * w, c = 0;
    test << "DONE\n";
    for (i = 1;i < n;i++) {
        test << dn[i] << " ";
    }
    test << endl;
    test << "changes\n";
    for (i = 1;i < n;i++) {
        test << change[i] << " ";
    }
    test << endl;
    test << "res\n";
    for (i = 1;i < n;i++) {
        c += dn[i];
        res -= change[i];
        res -= (n - 2 - c + dn[i]) * tm[i - 1];
        test << i _ change[i] _(n - 2 - c + dn[i]) * tm[i - 1] _ c _ dn[i] _ tm[i - 1] << endl;
        cout << res << " ";
        test << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, i = 0;
    cin >> t;
    while (t--) {
        // cout << "haha" _ i++ << endl;
        solve();
    }
}