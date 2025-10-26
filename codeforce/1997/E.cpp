#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

const ll N = 2e5 + 50;

int lazy[4 * N], st[4 * N], n, q;

void build(ll n) {
    for (ll i = 0;i < 4 * n;i++) {
        st[i] = 0;
        lazy[i] = 0;
    }
}

void add(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return;
    if (tl == l && tr == r) {
        lazy[v] ++;
        st[v] += tr - tl + 1;
        return;
    }
    ll tm = (tl + tr) / 2;
    if (lazy[v] > 0) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        st[2 * v] += lazy[v] * (tm - tl + 1);
        st[2 * v + 1] += lazy[v] * (tr - tm);
        lazy[v] = 0;
    }
    add(2 * v, tl, tm, l, min(r, tm));
    add(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    st[v] = st[2 * v] + st[2 * v + 1];
}

ll get(ll v, ll tl, ll tr, ll nd) {
    // test << "get" _ v _ tl _ tr _ nd << endl;
    ll tm = (tl + tr) / 2;
    if (tl == tr && tl == nd) return st[v];
    if (lazy[v] > 0) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        st[2 * v] += lazy[v] * (tm - tl + 1);
        st[2 * v + 1] += lazy[v] * (tr - tm);
        lazy[v] = 0;
    }
   
    if (nd > tm) return get(2 * v + 1, tm + 1, tr, nd);
    else return get(2 * v, tl, tm, nd);
}

vector < ll > eat;

ll find(ll k, vector < pair < ll, ll > >& qr) {
    ll l = 0, r = q - 1, m;
    while (l + 1 < r) {
        // test << "find" _ l _ r << endl;
        m = (l + r) / 2;
        if (get(1, 0, q - 1, m) / qr[m].ff+1 > k) {
            l = m;
        } else r = m;
    }
    test<<"find res" _ l _ r<<endl;
    if (get(1, 0, q - 1, l) / qr[l].ff+1 <= k) return l;
    if (get(1, 0, q - 1, r) / qr[r].ff+1 <= k) return r;
    return r+1;
}

void solve() {
    ll k, i, j, m, l, x, r, t, tmp;
    cin >> n >> q;
    ll a[n];
    vector < ll > b[n];
    for (i = 0;i < n;i++) cin >> a[i];
    vector < pair < ll, ll > > qr;
    for (i = 0;i < q;i++) {
        cin >> l >> x;
        b[l - 1].pb(i);
        qr.pb({ x, i });
    }
    sort(qr.begin(), qr.end());
    map < ll, ll > mp;
    bool res[q];
    eat.clear();
    for (i = 0;i < q;i++) {
        mp[qr[i].ss] = i;
        eat.pb(0);
    }
    build(q);
    // test<<"here\n";
    for (i = 0;i < n;i++) {
        test << i << endl;
        l = 0;
        for (j = 0;j < b[i].size();j++) {
            t = mp[b[i][j]];
            tmp = get(1, 0, q - 1, t);
            test<<"check" _ t _ tmp _ b[i][j] _ qr[t].ff <<endl;
            if (tmp/qr[t].ff+1 > a[i]) res[b[i][j]] = false;
            else res[b[i][j]] = true;
        }
        r = find(a[i], qr);
        test << " hmm " _ a[i] _ r << endl;
        test << " add " _ r _ q -1 << endl;
        add(1, 0, q - 1, r, q - 1);
    }
    for (i = 0;i < q;i++) {
        if (res[i]) cout << "YES\n";
        else cout << "NO\n";
    }

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
}