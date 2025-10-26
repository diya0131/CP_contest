
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

void calc(ll k, ll p, ll le, vector < vector < ll > >& path) {
    len[k] = le;
    for (int d : path[k]) {
        if (d != p) calc(d, k, le + w[k][d], path);
    }
}

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<vector<ll>>& adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<ll>>& adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
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
    LCA lca(path, 0);
    calc(0, -1, 0, path);
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