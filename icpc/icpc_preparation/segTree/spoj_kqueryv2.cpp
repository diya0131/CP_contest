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

vector < vector < ll > > tree;
vector < ll > a;

void build(ll v, ll tl, ll tr) {
    vector < ll > tmp;
    ll tm = (tl + tr) / 2;
    if (tl == tr) {
        if (tl < a.size()) {
            tmp.pb(a[tl]);
        }
        tree[v] = tmp;
    } else {
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge(ALL(tree[2 * v]), ALL(tree[2 * v + 1]), back_inserter(tree[v]));
    }

}

ll get(ll v, ll tl, ll tr, ll l, ll r, ll k) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        // ll l1=0, r1=tree[v].size()-1, m;
        // while(l1<=r1){
        //     m=(l1+r1)/2;
        //     if(tree[v][m]<=k) l1=m+1;
        //     else r1=m-1;
        // }
        
        ll s = tree[v].size() - (upper_bound(ALL(tree[v]), k)-tree[v].begin());
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
    vector < ll > tmp;
    vector < ll >::iterator it;
    for (i = 0; i < 4 * n; i++) {
        tree.pb(tmp);
    }
    // rma = 1 << (ll)ceil(log2(n));
    rma=n;
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