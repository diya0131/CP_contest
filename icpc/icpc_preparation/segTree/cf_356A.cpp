#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

vector < pair< ll, ll > > tree;

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val, ll ord) {
    if (l > r) return;
    if (tl == l && tr == r) {
        // cout<<l _ r _ v _ tree[v].ff _ val<<endl;
        if (tree[v].ff == 0) {
            tree[v] = {val, ord};
        }
    } else {
        ll tm = (tl + tr) / 2;
        modify(2 * v, tl, tm, l, min(tm, r), val, ord);
        modify(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val, ord);
    }
}

int get(ll v, ll tl, ll tr, ll pos, ll val, ll ord) {

    if (tree[v].ff != 0 && tree[v].ss<ord) {
        val = tree[v].ff;
        ord = tree[v].ss;
    }
    if (tl==tr){
        // cout<<endl<<"node: "<<v<<endl;
        return val;
    }
    ll tm = (tl + tr) / 2;
    if (pos <= tm) return get(2 * v, tl, tm, pos, val, ord);
    else return get(2 * v + 1, tm + 1, tr, pos, val, ord);
}

int main() {
    ll n, m, i, j, k, s, t, l, r, x;
    cin >> n >> m;
    for (i = 0;i < 4 * n;i++) tree.pb({0, -1});
    for (i = 0;i < m;i++) {
        cin >> l >> r >> x;
        modify(1, 0, n - 1, l - 1, x - 2, x , i);
        modify(1, 0, n - 1, x, r - 1, x , i);

    }
    for (i = 0;i < n;i++) {
        cout << get(1, 0, n - 1, i, 0, m) << " ";
    }
    cout << endl;
}