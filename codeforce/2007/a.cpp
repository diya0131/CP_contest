#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 1;
const ll INF = 1e18;

vector < vector < ll > > path;

vector < ll > vis;
ll res, n;

void dfs(vector < vector < ll > >& edges, vector < ll >& must, ll k, ll nd, ll c, ll cost) {
    ll i, j, s;
    if (c == k) {
        res = min(res, cost + path[nd][n - 1]);
        return;
    }
    for (i = 0;i < k;i++) {
        if (!vis[i]) {
            vis[i] = 1;
            if (path[nd][edges[must[i]][0]] != -1) dfs(edges, must, k, edges[must[i]][0], c + 1, cost + path[nd][edges[must[i]][0]]);
            if (path[nd][edges[must[i]][1]] != -1) dfs(edges, must, k, edges[must[i]][1], c + 1, cost + path[nd][edges[must[i]][1]]);
            vis[i] = 0;
        }
    }
}

void solve() {
    ll m, t, q, k, u, v, i, j, s, l;
    cin >> n >> m;
    vector < map < ll, ll > > adj(n);
    vector < vector < ll > > edges(m);
    vector < ll > tmp(3);
    path.assign(n, vector < ll >(n, -1));
    for (i = 0;i < m;i++) {
        test<<"hey" _ i<<endl;
        cin >> u >> v >> t;
        u--;
        v--;
        tmp[0] = u;
        tmp[1] = v;
        tmp[2] = t;
        edges[i] = tmp;
        if (adj[u].find(v) == adj[u].end()) {
            adj[u][v] = t;
        } else {
            adj[u][v] = min(adj[u][v], t);
        }
        path[u][v] = t;
        swap(u, v);
        if (adj[u].find(v) == adj[u].end()) {
            adj[u][v] = t;
        } else {
            adj[u][v] = min(adj[u][v], t);
        }
        path[u][v] = t;
    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            for (l = 0;l < n;l++) {
                if (path[j][i] == -1 || path[i][l] == -1) continue;
                if (path[j][l] > path[j][i] + path[i][l]) {
                    path[j][l] = path[j][i] + path[i][l];
                }
            }
        }
    }

    cin >> q;
    while (q--) {
        cin >> k;
        vector< ll > must(k);
        for (i = 0;i < k;i++) {
            cin >> must[i];
        }
        vis.clear();
        vis.assign(n, 0);
        res = INF;
        dfs(edges, must, k, 0, 0, 0);
        cout<<res<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while (t--) solve();
}