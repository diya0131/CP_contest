//https://www.spoj.com/problems/KQUERY/

#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define debug(a) cout << #a << " = " << a << endl;
#define _ <<" "<<



using namespace std;

vector < multiset < ll > > tree;
vector < ll > a;

void build(ll v, ll tl, ll tr) {
    multiset < ll > tmp;
    ll tm = (tl + tr) / 2;
    if (tl == tr) {
        if (tl < a.size()) {
            tmp.insert(a[tl]);
        }
        tree[v] = tmp;
    } else {
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge(ALL(tree[2 * v]), ALL(tree[2 * v + 1]), inserter(tree[v], tree[v].begin()));
    }

}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
    multiset < ll > tmp;
    ll tm = (tl + tr) / 2;
    if (tl == tr && tl == pos) {
        tmp.insert(val);
        tree[v] = tmp;
    } else {
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, val);
        } else {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        tree[v].clear();
    }

}

ll get(ll v, ll tl, ll tr, ll l, ll r, ll k) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        ll s = tree[v].size() - distance(tree[v].begin(), upper_bound(ALL(tree[v]), k));
        return s;
    } else {
        ll tm = (tl + tr) / 2;
        ll res = get(2 * v, tl, tm, l, min(r, tm), k) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k);
        return res;
    }
}

int main() {
    cin.tie(0);cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, i, j, k, s, t, m, rma;
    cin >> n;
    multiset < ll > tmp;
    multiset < ll >::iterator it;
    for (i = 0; i < 4 * n; i++) {
        tree.pb(tmp);
    }
    rma = 1 << (ll)ceil(log2(n));
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(1, 0, rma - 1);
    cin >> m;
    while (m--) {
        cin >> i >> j >> k;
        cout << get(1, 0, rma - 1, i - 1, j - 1, k) << endl;
    }
}