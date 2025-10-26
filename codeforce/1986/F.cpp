#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool debug = false;

struct node {
    vector < ll > path;
    vector < ll > parent;
    ll rank;
    ll anc = INT_MAX;
    ll active = true;
    ll count = 0;
};

vector < node > arr;
vector < bool > vis;
vector < pair < ll, ll > > queries;
vector < vector < int > > pa;

void build(ll nd, ll r, ll par) {
    if (debug) cout << "build: " << nd _ r _ par _ arr[nd].path.size() << endl;
    arr[nd].rank = r;
    if (debug) cout << "par " _ nd _ 0 _ par << endl;
    arr[nd].parent.pb(par);

    ll q = 2;
    while (q <= r) {
        if (debug) cout << "par " _ nd _ q _ arr[arr[nd].parent[q / 2 - 1]].parent[q / 2 - 1] << endl;
        arr[nd].parent.pb(arr[arr[nd].parent[q / 2 - 1]].parent[q / 2 - 1]);
        q *= 2;
    }
    arr[nd].parent.pb(-1);
    for (ll i = 0;i < arr[nd].path.size();i++) {
        if (arr[nd].path[i] != par) {
            build(arr[nd].path[i], r + 1, nd);
        }
    }
}

ll lca(ll x, ll y) {
    if (debug) cout << "lca " _ x _ y << endl;
    ll p;
    if (arr[x].rank < arr[y].rank) swap(x, y);
    while (arr[x].rank != arr[y].rank) {
        if (debug) cout << arr[x].rank _ "--" _ arr[y].rank << endl;
        p = 0;
        while (arr[x].parent[p]!=-1 && arr[arr[x].parent[p]].rank > arr[y].rank) {
            if (debug) cout << arr[arr[x].parent[p]].rank _ p << endl;
            p++;
            
        }
        if (arr[x].parent[p]==-1 || arr[arr[x].parent[p]].rank < arr[y].rank) p--;
        x = arr[x].parent[p];
    }
    if (debug) cout << x _ y << endl;
    if (x == y) return x;
    while (arr[x].parent[0] != arr[y].parent[0]) {
        p = 0;
        while (arr[x].parent[p] != arr[y].parent[p]) {
            p++;
        }
        x = arr[x].parent[p - 1];
        y = arr[y].parent[p - 1];
    }
    return arr[x].parent[0];
}

pair< ll, ll > go(ll nd) {

    ll r = arr[nd].anc, s = 0;
    pair < ll, ll >pr;
    for (ll i = 0;i < arr[nd].path.size();i++) {
        if (arr[nd].path[i] != arr[nd].parent[0]) {
            pr = go(arr[nd].path[i]);
            r = min(r, pr.first);
            s += pr.second;
        }
    }
    if (debug) cout << "go: " << nd _ r << endl;
    arr[nd].count = s + 1;
    if (r != -1 && r < arr[nd].rank) {
        arr[nd].active = false;
    }
    return { r, s + 1 };
}

void tree(int nd, int par){
    vis[nd]=true;
    for(int i=0;i<pa[nd].size();i++){
        if(pa[nd][i]!=par){
            if(vis[pa[nd][i]]){
                queries.pb({nd, pa[nd][i]});
            } else{
                arr[nd].path.pb(pa[nd][i]);
                arr[pa[nd][i]].path.pb(nd);
                tree(pa[nd][i], nd);
            }
        }
    }
}

void solve() {
    arr.clear();
    ll n, i, j, k, l, m, s, x, y, p;
    cin >> n >> m;
    arr.clear();
    vis.clear();
    pa.clear();
    queries.clear();

    pa.resize(n);
    arr.resize(n);
    vis.resize(n, 0);
    
    
    for (i = 0;i < m;i++) {
        cin >> x >> y;
        x--; y--;
        pa[x].pb(y);
        pa[y].pb(x);
    }

    tree(0, -1);

    build(0, 0, -1);
    if (debug) cout << "built\n";
    for (i = 0;i < queries.size();i++) {
        x = queries[i].first;
        y = queries[i].second;
        p = lca(x, y);
        if (debug) cout << "P " << p _ arr[p].rank << endl;
        arr[x].anc = min(arr[x].anc, arr[p].rank);
        arr[y].anc = min(arr[y].anc, arr[p].rank);
    }
    if (debug) cout << "lca done\n";
    // cout << "lca done\n";
    go(0);
    if (debug) cout << "marking done\n";
    ll res = 0;
    for (i = 1;i < n;i++) {
        if (debug) cout << i _ arr[i].active _ arr[i].count << endl;
        if (arr[i].active) {
            res = max(res, (arr[i].count * (n - arr[i].count)));
        }
    }
    if(debug) cout<<"res ";
    cout << n * (n - 1) / 2 - res << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}