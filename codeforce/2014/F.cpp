#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

vector < vector < ll > > adj;
vector< ll > a;

ll res, c;

pair < ll, ll> dfs(ll k, ll p) {
    pair < ll, ll> pr, t;
    // cout<<k _ p <<endl;
    pr = { a[k], 0 };
    for (ll to : adj[k]) {
        if (to != p) {
            t = dfs(to, k);
            pr.ff += max(t.ff - 2 * c, t.ss);
            pr.ss += max(t.ff, t.ss);
        }
    }
    return pr;
}

void solve() {
    ll n, i, j, k, s, t, u, v;
    cin >> n >> c;
    a.resize(n);
    adj.clear();
    adj.resize(n);
    for (i = 0;i < n;i++) cin >> a[i];
    for (i = 1;i < n;i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pair < ll, ll> pr;
    pr = dfs(0, -1);
    cout << max(pr.ff, pr.ss) << endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}