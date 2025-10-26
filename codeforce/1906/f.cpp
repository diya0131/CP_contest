#include<bits/stdc++.h>
#include<chrono>
#include <random>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); test.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

const bool TEST = 0;

struct data1{
    ll sum = 0;
    ll pref = 0;
    ll suff = 0;
    ll val = 0;
    ll mx = LLONG_MIN;
};

vector < data1 > st(4e5);

data1 combine(data1& left, data1& right) {
    data1 res;
    res.sum = left.sum + right.sum;
    res.suff = max(right.suff, left.suff + right.sum);
    res.pref = max(left.pref, right.pref + left.sum);
    res.val = max(max(right.val, left.val), left.suff + right.pref);
    
    res.mx = max(right.mx, left.mx);
    return res;
}

void update(ll v, ll tl, ll tr, ll idx, ll k) {
    if (tl == tr) {
        st[v].sum = k;
        if (k >= 0) {
            st[v].pref = st[v].suff = st[v].val = k;
        } else {
            st[v].pref = st[v].suff = st[v].val = 0;
        }
        st[v].mx = k;
        return;
    }
    ll tm = (tl + tr) / 2;
    if (tm < idx) update(2 * v + 1, tm + 1, tr, idx, k);
    else update(2 * v, tl, tm, idx, k);
    st[v] = combine(st[2 * v], st[2 * v + 1]);
}

data1 get(ll v, ll tl, ll tr, ll l, ll r) {
    data1 dt;
    
    if (l > r) {
        return dt;
    }
    if (tl == l && tr == r) {
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    data1 left = get(2 * v, tl, tm, l, min(r, tm));
    data1 right = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    // cout<<left.mx _ right.mx<<endl;
    return combine(left, right);
}

void solve() {
    ll n, m, i, j, k, s, t, l, r, c = 1;
    cin >> n >> m;
    vector < vector< pair < ll, ll > > > op(n + 2);
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        op[l].pb({ i, k });
        op[r + 1].pb({ i, 0 });
    }
    ll q;
    cin >> q;
    vector < vector< ll > > qu(q, vector< ll>(4));
    vector< ll > res(q);
    data1 vc;
    for(i=0;i<4*m;i++) st[i].mx = 0; 
    for (i = 0;i < q;i++) {
        cin >> k >> l >> r;
        qu[i][0] = k;
        qu[i][1] = l - 1;
        qu[i][2] = r - 1;
        qu[i][3] = i;
    }
    sort(ALL(qu), [&](vector< ll >& x, vector< ll >& y) { return x[0]<y[0];});
    for (i = 0;i < q;i++) {
        while (c <= qu[i][0]) {
            for (j = 0;j < op[c].size();j++) {
                update(1, 0, m - 1, op[c][j].ff, op[c][j].ss);
            }
            c++;
        }
        vc = get(1, 0, m - 1, qu[i][1], qu[i][2]);
        if (vc.val) res[qu[i][3]] = vc.val;
        else res[qu[i][3]] = vc.mx;
    }
    for (i = 0;i < q;i++) cout << res[i] << endl;
}

int main() {
    BOOST
        solve();
}