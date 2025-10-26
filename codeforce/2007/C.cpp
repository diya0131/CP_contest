#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;


void solve() {
    ll n, m, i, k, mx = 0, l, r, a, b, q;
    cin >> n >> a >> b;
    q = gcd(a, b);
    set< ll > st;
    set< ll >::iterator it, it2, it3;

    for (i = 0;i < n;i++) {
        cin >> k;
        st.insert(k % q);
    }
    if (st.size() == 1) {
        cout << 0 << endl;
        return;
    }
    ll res = *prev(st.end()) - *st.begin();
    for (it = st.begin();next(it) != st.end();it++) {
        res = min(res, q + *it - *next(it));
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}