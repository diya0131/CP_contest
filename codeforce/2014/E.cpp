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

vector < vector< pair < ll, ll > > > adj;
vector < ll > start_min, end_min;
set < ll > horse;

void solve() {
    ll n, m, h, i, j, k, u, v, w, s;
    cin >> n >> m >> h;
    pair < ll, pair < ll, bool > > pr;
    adj.clear();
    adj.resize(n);
    horse.clear();
    while (h--) {
        cin >> k;
        test << "horser" _ k - 1 << endl;
        horse.insert(k - 1);
    }
    for (i = 0;i < m;i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({ v, w });
        adj[v].pb({ u, w });
    }
    start_min.clear();
    start_min.assign(n, LLONG_MAX);
    end_min.clear();
    end_min.assign(n, LLONG_MAX);

    vector< bool > vis(n, 0);
    vector< bool > vis_horse(n, 0);
    priority_queue < pair < ll, pair < ll, bool > >, vector < pair < ll, pair < ll, bool > >>, greater< pair < ll, pair < ll, bool > >> > q;
    q.push({ 0, {0, 0} });
    while (!q.empty()) {
        pr = q.top();
        pr.ss.ss = pr.ss.ss | (horse.count(pr.ss.ff) > 0);
        // test<<pr.ff _ pr.ss.ff _ pr.ss.ss _ (0 | horse.count(pr.ss.ff))<<endl;
        q.pop();
        if (!vis[pr.ss.ff] || (pr.ss.ss && !vis_horse[pr.ss.ff])) {
            start_min[pr.ss.ff] = min(start_min[pr.ss.ff], pr.ff);
            if (pr.ss.ss) vis_horse[pr.ss.ff] = 1;
            vis[pr.ss.ff] = 1;
            for (auto to : adj[pr.ss.ff]) {
                if (!vis[to.ff] || (pr.ss.ss && !vis_horse[to.ff])) {
                    s = pr.ff;
                    if (pr.ss.ss) s += to.ss / 2;
                    else s += to.ss;
                    q.push({ s, {to.ff, pr.ss.ss} });
                }
            }
        }
    }
    vis.assign(n, 0);
    vis_horse.assign(n, 0);
    q.push({ 0, {n - 1, 0} });
    while (!q.empty()) {
        pr = q.top();
        pr.ss.ss = pr.ss.ss | (horse.count(pr.ss.ff) > 0);
        test << pr.ff _ pr.ss.ff _ pr.ss.ss _ horse.count(pr.ss.ff) << endl;
        q.pop();
        if (!vis[pr.ss.ff] || (pr.ss.ss && !vis_horse[pr.ss.ff])) {
            end_min[pr.ss.ff] = min(end_min[pr.ss.ff], pr.ff);
            if (pr.ss.ss) vis_horse[pr.ss.ff] = 1;
            vis[pr.ss.ff] = 1;
            for (auto to : adj[pr.ss.ff]) {
                if (!vis[to.ff] || (pr.ss.ss && !vis_horse[to.ff])) {
                    s = pr.ff;
                    if (pr.ss.ss) s += to.ss / 2;
                    else s += to.ss;
                    q.push({ s, {to.ff, pr.ss.ss} });
                }
            }
        }
    }
    ll res = LLONG_MAX;
    for (i = 0;i < n;i++) {
        test << i _ start_min[i] _ end_min[i] << endl;
        if (start_min[i] != LLONG_MAX && end_min[i] != LLONG_MAX) {
            res = min(res, max(start_min[i], end_min[i]));
        }
    }
    if (res == LLONG_MAX) cout << -1;
    else cout << res;
    cout << endl;
}

int main() {
    // BOOST


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}