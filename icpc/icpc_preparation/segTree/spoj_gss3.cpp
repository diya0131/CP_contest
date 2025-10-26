#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

struct myNode {
    ll ma = INT_MIN;
    ll sum = 0;
    ll prefix = 0;
    ll suffix = 0;
    ll ans = 0;
};

vector < myNode > tree;

myNode combine(myNode l, myNode r) {
    myNode nd;
    nd.sum = l.sum + r.sum;
    nd.ma = max(l.ma, r.ma);
    nd.prefix = max(l.prefix, l.sum + r.prefix);
    nd.suffix = max(r.suffix, l.suffix + r.sum);
    nd.ans = max(l.suffix + r.prefix, max(l.ans, r.ans));
    return nd;
}

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    myNode nd;
    if (tl == tr) {
        nd.ma = a[tl];
        nd.sum = a[tl];
        if (a[tl] > 0) {
            nd.ans = a[tl];
            nd.prefix = a[tl];
            nd.suffix = a[tl];
        } else {
            nd.ans = 0;
            nd.prefix = 0;
            nd.suffix = 0;
        }
        tree[v] = nd;
    } else {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

void modify(ll v, ll tl, ll tr, ll pos, ll val) {
    myNode nd;
    if (tl == tr) {
        nd.ma = val;
        nd.sum = val;
        if (val > 0) {
            nd.ans = val;
            nd.prefix = val;
            nd.suffix = val;
        } else {
            nd.ans = 0;
            nd.prefix = 0;
            nd.suffix = 0;
        }
        tree[v] = nd;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) modify(2 * v, tl, tm, pos, val);
        else modify(2 * v + 1, tm + 1, tr, pos, val);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

myNode get(ll v, ll tl, ll tr, ll l, ll r) {
    // cout<<v _ l _ r _ tl _ tr<<endl;
    myNode nd;
    if( l>r ) return nd;
    if (tl == l && tr == r) {
        return tree[v];
    }
    else{
        ll tm = (tl+tr)/2;
        return combine(get(2*v, tl, tm, l, min(r, tm)), get(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
}



int main() {
    ll n, i, j, s, t, k, m, x, y;
    cin >> n;
    myNode nd;
    for (i = 0;i < 4 * n;i++) {
        tree.pb(nd);
    }
    vector < ll > a;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(a, 1, 0, n - 1);
    // for(i=0;i<4*n;i++){
    //     cout<<i<<": "<<tree[i].sum _ tree[i].prefix _ tree[i].suffix _ tree[i].ans <<endl;
    // }

    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> x >> y >> k;
        if (x) {
            nd = get(1, 0, n - 1, y-1, k-1);
            if(nd.ma<0) cout<<nd.ma<<endl;
            else cout<< nd.ans <<endl;
        } else {
            a[y - 1] = k;
            modify(1, 0, n - 1, y - 1, k);
        }
    }
}