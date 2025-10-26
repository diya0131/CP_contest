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
const ll M = 1e9 + 7;

vector < int > st, lazy;

void paint(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return;
    if (tl == l && tr == r) {
        test << "paint: " _ v _ tl _ tr << endl;
        lazy[v] = 1;
        st[v] = tr - tl + 1;
        return;
    }
    ll tm = (tl + tr) / 2;
    if (lazy[v]) {
        st[2 * v] = tm - tl + 1;
        st[2 * v + 1] = tr - tm;
        lazy[2 * v] = 1;
        lazy[2 * v + 1] = 1;
    }
    paint(2 * v, tl, tm, l, min(tm, r));
    paint(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    st[v] = st[2 * v] + st[2 * v + 1];
    test << "back" _ st[v] _ tl _ tr << endl;
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (tl > l || tr < r) {
        test << "error: " _ v _ tl _ tr _ l _ r << endl;
    }
    if (l > r) return 0;
    if (lazy[v]) {
        return r - l + 1;
    }
    if (tl == l && tr == r) {
        test << "get: " _ v _ lazy[v] _ tr - tl + 1 _ st[v] << endl;
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);

}

void solve() {
    ll n, k, i, j, x = 0, y = 0, m, pr, sf, l, r, add;
    cin >> n >> m;
    vector < ll > pref(n + 1, -1), suff(n + 1, n);
    vector < vector < ll >  > a(n);
    vector < pair < ll, ll > > fr(m);
    for (i = 0;i < m;i++) {
        cin >> x >> y;
        x--; y--;
        a[x].pb(i + 1);
        a[y].pb(i + 1);
        fr[i] = { x, y };
    }
    st.clear();
    st.resize(4 * n, 0);
    lazy.clear();
    lazy.resize(4 * n, 0);
    stack< pair < ll, ll >  > sta;
    map < ll, ll > mp;
    k = 0;
    for (i = 1;i <= n;i++) {
        for (j = 0;j < a[i - 1].size();j++) {
            mp[a[i - 1][j]]++;
            sta.push({ i - 1, a[i - 1][j] });
        }
        while (!sta.empty() && mp[sta.top().ss] == 2) {
            sta.pop();
        }
        if (!sta.empty()) {
            pref[i] = sta.top().ff;
        }
    }
    while (!sta.empty()) sta.pop();
    mp.clear();
    for (i = n - 1;i >= 0;i--) {
        for (j = 0;j < a[i].size();j++) {
            mp[a[i][j]]++;
            sta.push({ i, a[i][j] });
        }
        while (!sta.empty() && mp[sta.top().ss] == 2) {
            sta.pop();
        }
        if (!sta.empty()) suff[i] = sta.top().ff;
    }
    vector < ll > sumpref(n + 1, 0), sumsuff(n + 1, 0), mipref(n + 1, 0), misuff(n + 1, 0);
    for (i = 0;i < n;i++) {
        for (j = 0;j < a[i].size();j++) {
            test << i _ a[i][j] _ fr[a[i][j] - 1].ff _ fr[a[i][j] - 1].ss << endl;
            if (fr[a[i][j] - 1].ss == i) {
                test << "s paint " _ fr[a[i][j] - 1].ff + 1 _ fr[a[i][j] - 1].ss << endl;
                paint(1, 0, n - 1, fr[a[i][j] - 1].ff + 1, fr[a[i][j] - 1].ss);
            }
        }
        sumpref[i + 1] = get(1, 0, n - 1, 0, i);
        pr = pref[i + 1];
        mipref[i + 1] = get(1, 0, n - 1, 0, pr);
    }

    st.clear();
    lazy.clear();
    st.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    test << "-------------------------------\n";
    for (i = n - 1;i >= 0;i--) {
        for (j = 0;j < a[i].size();j++) {
            test << i _ a[i][j] _ fr[a[i][j] - 1].ff _ fr[a[i][j] - 1].ss << endl;
            if (fr[a[i][j] - 1].ff == i) {
                test << "s paint " _ fr[a[i][j] - 1].ff + 1 _ fr[a[i][j] - 1].ss << endl;
                paint(1, 0, n - 1, fr[a[i][j] - 1].ff + 1, fr[a[i][j] - 1].ss);
            }
        }
        test << i _ " - - \n";
        sumsuff[i] = get(1, 0, n - 1, i, n - 1);
        sf = suff[i];
        misuff[i] = get(1, 0, n - 1, sf + 1, n - 1);
    }
    ll res = sumpref[n];
    for (i = 0;i <= n;i++) {
        test << pref[i] << " ";
    }
    test << endl;
    for (i = 0;i <= n;i++) {
        test << suff[i] << " ";
    }
    test << endl;
    for (i = 0;i <= n;i++) {
        test << sumpref[i] << " ";
    }
    test << endl;
    for (i = 0;i <= n;i++) {
        test << sumsuff[i] << " ";
    }
    test << endl;
    for (i = 0;i <= n;i++) {
        test << mipref[i] << " ";
    }
    test << endl;
    for (i = 0;i <= n;i++) {
        test << misuff[i] << " ";
    }
    test << endl;
    for (i = 1;i < n;i++) {
        k = 0;
        pr = pref[i];
        sf = suff[i];
        // if (pr == -1) add = 0;
        // else add = pr;
        k += sumpref[i] - mipref[i] + pr + 1;
        if (sf == n) add = 0;
        else add = n - sf - 1;
        k += sumsuff[i] - misuff[i] + add;

        test << pr _ i _ sf << endl;
        test << sumpref[i] - mipref[i] _ sumsuff[i] - misuff[i] _ pr + 1 + n - sf - 1 << endl;
        res = min(res, k);
    }
    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}