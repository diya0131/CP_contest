// https://www.spoj.com/problems/LCA/

#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define PLL pair < ll, ll >
#define _ <<" "<<

using namespace std;

const bool te = false;
const ll N = 1005;



ll st[4 * N];

vector < ll > arr, nodes;
map < ll, ll > mp;
void dfs(ll k, ll p, ll lvl, vector < vector < ll > >& path) {
    mp[k] = nodes.size();
    nodes.pb(k);
    arr.pb(lvl);
    for (int i = 0;i < path[k].size();i++) {
        if (path[k][i] != p) {
            dfs(path[k][i], k, lvl + 1, path);
            nodes.pb(k);
            arr.pb(lvl);
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
    if (arr[st[2 * v]] > arr[st[2 * v + 1]]) st[v] = st[2 * v + 1];
    else st[v] = st[2 * v];
    test << st[v] _ v _ tl _ tr _ arr[st[2 * v]] _ arr[st[2 * v + 1]] << endl;
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return -1;
    if (tl == l && tr == r) {
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    ll le = get(2 * v, tl, tm, l, min(r, tm));
    ll ri = get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    if (le == -1) return ri;
    if (ri == -1) return le;
    if (arr[le] > arr[ri]) return ri;
    else return le;
}


void solve(int cs) {
    ll n, i, j, k, s, m, q, l, r;
    cin >> n;
    arr.clear();
    nodes.clear();
    mp.clear();

    vector < vector < ll > > path(n);
    for (i = 0;i < n;i++) {
        cin >> m;
        for (j = 0;j < m;j++) {
            cin >> k;
            path[i].pb(k - 1);
        }
    }
    dfs(0, -1, 0, path);
    ll sz = arr.size();
    build(1, 0, sz - 1);
    for (i = 0;i < sz;i++) {
        test << arr[i] << " \n"[i == sz - 1];
    }
    for (i = 0;i < sz;i++) {
        test << nodes[i] << " \n"[i == sz - 1];
    }
    cin >> q;
    cout << "Case" _ cs + 1 << ":\n";
    while (q--) {
        cin >> l >> r;
        l=mp[l - 1]; r= mp[r - 1];

        if( l > r) swap(l, r);
        test << l _ r << endl;
        cout << nodes[get(1, 0, sz - 1, l, r)] + 1 << endl;
    }

}
int main() {
    int t;
    cin >> t;
    for (int i = 0;i < t;i++) solve(i);
}