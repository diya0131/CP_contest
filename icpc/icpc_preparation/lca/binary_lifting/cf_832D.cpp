#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<
#define test if(te) cout
#define ff first
#define ss second

using namespace std;

const bool te = false;

ll n, m, timer;
vector < vector < ll > > adj, up;
vector < ll > tin, tout, he;

void dfs(ll k, ll p, ll h) {
    tin[k] = timer++;
    up[k][0] = p;
    he[k] = h;
    for (int i = 1;i < m;i++) {
        up[k][i] = up[up[k][i - 1]][i - 1];
    }
    for (int to : adj[k]) {
        if (to != p) {
            dfs(to, k, h + 1);
        }
    }
    tout[k]=timer++;
}

void preprocess() {
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    he.resize(n);
    m = ceil(log2(n)) + 1;
    up.assign(n, vector < ll >(m));
    dfs(0, 0, 0);
}

bool isA(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll get(ll u, ll v) {
    test << he[u] _ he[v] _ u _ v _ isA(u,v) _ isA(v, u)<< endl;
    if (isA(u, v)) return he[v] - he[u] + 1;
    if (isA(v, u)) return he[u] - he[v] + 1;
    ll t = u;
    for (int i = m - 1;i >= 0;i--) {
        if (!isA(up[u][i], v)) u = up[u][i];
    }
    u = up[u][0];
    test<< " : " _ u _ t _ v _ he[u] _ he[t] _ he[v]<<endl;
    return -2 * he[u] + he[t] + he[v] + 1;
}

int main() {
    ll q, i, j, k, s, t, a, b, c, u, v, x, y, z;

    cin >> n >> q;
    adj.clear();
    adj.resize(n);
    for (i = 1;i < n;i++) {
        cin >> k;
        adj[k - 1].pb(i);
        adj[i].pb(k - 1);
    }
    preprocess();
    while (q--) {
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        x = get(a, b);
        y = get(a, c);
        z = get(c, b);
        test << x _ y _ z << endl;
        cout <<( x + y + z - 2 * min(x, min(y, z))+1)/2 << endl;
    }
}