// https://cses.fi/problemset/task/1736
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const ll N = 2e5 + 5;

ll st[4 * N] = { 0 }, lazy[4 * N] = { 0 }, diff[4 * N] = { 0 };
vector < ll > a;
bool debug;
void push(ll v, ll tl, ll tr, ll tm) {
    ll k = lazy[v];
    ll l;
    if (k > 0) {
        l = tm - tl + 1;
        lazy[2 * v] += k;

        st[2 * v] += k * l + diff[v] * l * (l - 1) / 2;


        l = tr - tm;
        lazy[2 * v + 1] += k + tm - tl + 1;
        st[2 * v + 1] += (k + tm - tl + 1) * l + diff[v] * l * (l - 1) / 2;
        diff[2 * v + 1] += diff[v];
        diff[2 * v] += diff[v];
        diff[v] = 0;
        lazy[v] = 0;
    }

}

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll ini) {
    // if (debug) cout << "--" << v _ tl _ tr _ l _ r _ ini << endl;
    ll s;
    if (l > r) return;
    if (tl == l && tr == r) {
        // if (debug) cout << "-set-" << v _ tl _ tr _ l _ r _ ini << endl;
        lazy[v] += ini;
        diff[v]++;
        st[v] += ini * (tr - tl + 1) + 1 * (tr - tl) * (tr - tl + 1) / 2;

        s = 0;
        for (int i = tl;i <= tr;i++) {
            s += a[i];
        }
        if (s != st[v]) {
            cout << "report " << v _ tl _ tr _ l _ r _ ini _ s _ st[v] << endl;
        }
        return;
    }
    ll tm = (tl + tr) / 2;
    push(v, tl, tr, tm);
    update(2 * v, tl, tm, l, min(r, tm), ini);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, ini + max(l, tm + 1) - l);
    st[v] = st[2 * v] + st[2 * v + 1];
    s = 0;
    for (int i = tl;i <= tr;i++) {
        s += a[i];
    }
    if (s != st[v]) {
        cout << "report " << v _ tl _ tr _ l _ r _ ini _ s _ st[v] << endl;
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    ll s, val;
    if (l > r) return 0;
    if (tl == l && tr == r) {
        s = 0;
        for (int i = tl;i <= tr;i++) {
            s += a[i];
        }
        if (s != st[v]) {
            cout << "report err" << v _ tl _ tr _ l _ r _ s _ st[v] << endl;
        }
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    push(v, tl, tr, tm);
    val = get(2 * v, tl, tm, l, min(tm, r)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    s = 0;
    for (int i = tl;i <= tr;i++) {
        s += a[i];
    }
    if (s != st[v]) {
        cout << "report err" << v _ tl _ tr _ l _ r _ s _ st[v] << endl;
    }
    return val;
}

void printT(ll n) {
    for (int i = 1;i < 4 * n;i++) {
        cout << i _ st[i] _ lazy[i] << endl;
    }
}

int main() {
    freopen("test_input.txt", "r", stdin);
    ll n, q, i, j, t, k, x, y;
    cin >> n >> q;

    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(a, 1, 0, n - 1);
    q = 16;
    while (q--) {
        cin >> k >> x >> y;
        if (q == 4) debug = true;
        cout << "query " << k _ x _ y << endl;
        if (k == 1) {
            for (i = x - 1;i < y;i++) {
                a[i] += i - x + 2;
            }
            update(1, 0, n - 1, x - 1, y - 1, 1);
            // printT(n);

        } else {
            cout << get(1, 0, n - 1, x - 1, y - 1) << endl;
            // printT(n);
        }
    }
}