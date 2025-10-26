#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<
#define test if(te) cout

using namespace std;

const bool te = 0;

const ll N = 1e5;

void solve() {
    ll n, m, i, k, j, s, l, p, t1;
    cin >> n >> m;
    vector < pair < ll, ll > > a(n);
    pair < ll, ll > pr;
    set< ll > st;
    set< ll >::iterator it;
    for (i = 0;i < n;i++) {
        cin >> l;
        st.clear();
        for (j = 0;j < l;j++) {
            cin >> k;
            st.insert(k);
        }
        k = 0;
        it = st.begin();
        while (it != st.end() && k == (*it)) {
            k++;
            it = next(it);
        }
        pr.ff = k;
        k++;
        while (it != st.end() && k == (*it)) {
            k++;
            it = next(it);
        }
        pr.ss = k;
        a[i] = pr;
    }
    map < ll, ll > mp;
    sort(ALL(a));
    for (i = n - 1;i >= 0;i--) {
        if (mp.find(a[i].ss) == mp.end()) {
            if (mp.find(a[i].ff) == mp.end()) mp[a[i].ff] = a[i].ss;
            else  mp[a[i].ff] = max(mp[a[i].ff], a[i].ss);
        } else {
            if (mp.find(a[i].ff) == mp.end()) mp[a[i].ff] = mp[a[i].ss];
            else  mp[a[i].ff] = max(mp[a[i].ff], mp[a[i].ss]);
        }
        test << a[i].ff _ mp[a[i].ff] << endl;
    }
    ll res = 0, ma = -1;
    test << res << endl;
    p = 0;
    for (auto ite = mp.begin();ite != mp.end();ite++) {
        test << ite->ff _ ite->ss _ ma << endl;
        if (ite->ff > m) break;
        if (ite->ss > ma) {
            if (ma >= ite->ff-1) {
                res += (ite->ff - p) * ma;
            } else {
                res += (ma - p + 1) * ma;
                t1 = ite->ff - 1;
                res += (t1 * (t1 + 1) / 2 - ma * (ma + 1) / 2);
            }
            test << "+" _ ite->ff _ ite->ss _ p _ ma _ res << endl;
            p = ite->ff;
            ma = ite->ss;
        }
    }
    if (ma > m) {
        res += (m + 1 - p) * ma;
    } else {
        res += (ma - p + 1) * ma;
        res += (m * (m + 1) / 2 - ma * (ma + 1) / 2);
        test << (m * (m + 1) / 2 - ma * (ma + 1) / 2) << endl;
    }

    cout << res << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();

}