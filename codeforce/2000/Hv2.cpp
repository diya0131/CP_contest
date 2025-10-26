#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;
const ll N = 2e6;

set < int > a;
set < int >::iterator it;

int st[4 * N];

void change(ll v, ll tl, ll tr, ll k) {
    if (tl == tr) {
        it = lower_bound(ALL(a), tl);
        if (*it != tl) st[v] = 0;
        else st[v] = (*next(it) - *it);
        return;
    }
    ll tm = (tl + tr) / 2;
    if (k > tm) change(2 * v + 1, tm + 1, tr, k);
    else change(2 * v, tl, tm, k);
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void solve() {

    ll n, i, j, k, s, t, m, pre, nxt, l, r, v, mid;
    cin >> n;
    a.clear();
    a.insert(0);
    vector < ll > res;
    a.insert(N + 1);
    vector < ll > b(n);
    for (i = 0;i < n;i++) {
        cin >> b[i];
    }
    a.insert(ALL(b));
    change(1, 0, N, 0);
    for (i = 0;i < n;i++) {
        change(1, 0, N, b[i]);
    }
    // build(1, 0, N);
    cin >> m;
    char ch;
    while (m--) {
        cin >> ch >> k;
        if (ch == '?') {
            l = 0, r = N;
            v = 1;
            if (st[v] > k) {
                while (l < r) {
                    mid = (l + r) / 2;
                    if (st[2 * v] > k) {
                        v = 2 * v;
                        r = mid;
                    } else {
                        v = 2 * v + 1;
                        l = mid + 1;
                    }
                }
                res.pb(l + 1);
            } else {
                res.pb(*prev(a.end()));
            }
            continue;
        }
        if (ch == '+') {
            it = lower_bound(ALL(a), k);
            nxt = *it;
            pre = *prev(it);
            a.insert(k);
        } else {
            it = lower_bound(ALL(a), k);
            pre = *prev(it);
            nxt = *next(it);
            a.erase(it);
        }
        change(1, 0, N, k);
        change(1, 0, N, pre);
        change(1, 0, N, nxt);
    }
    vector<ll> del(a.begin(), a.end());
    a.clear();
    a.insert(N + 1);
    for (int i = 0; i < del.size() - 1;i++) {
        change(1, 0, N, del[i]);
    }
    for (int tr : res) cout << tr << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}