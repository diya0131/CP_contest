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

void solve() {
    ll n, i, j, k, s, t, q, pr1, pr2, nx1, nx2, c, v;
    cin >> n;
    ll b[n];
    vector < pair < ll, ll > > a;
    vector < ll > res(n + 3);
    for (i = 0;i < n;i++) {
        cin >> k;
        b[i] = k;
        a.pb({ k, i + 1 });
        res[i + 1] = 0;
    }
    res[n + 1] = 0;
    res[n + 2] = 0;
    sort(ALL(a));
    multiset < ll > st;
    multiset < ll >::iterator it;
    st.insert(0);
    st.insert(0);
    st.insert(n + 1);
    st.insert(n + 1);
    for (i = 0;i < n;i++) {
        st.insert(a[i].ss);
        it = st.find(a[i].ss);
        c = *it;
        v = b[c - 1];
        pr1 = *prev(it);
        pr2 = *prev(prev(it));
        nx1 = *next(it);
        nx2 = *next(next(it));
        test << pr2 _ pr1 _ c _ nx1 _ nx2 << endl;

        res[0] += (c - pr1) * (nx1 - c) * v;
        res[pr1] -= (c - pr1) * (nx1 - c) * v;
        test << 0 _ pr1 _ (c - pr1) * (nx1 - c) * v<<endl;

        res[nx1 + 1] += (c - pr1) * (nx1 - c) * v;
        res[n + 2] -= (c - pr1) * (nx1 - c) * v;
        test << nx1 + 1 _ n + 2 _ (c - pr1) * (nx1 - c) * v<<endl;
        

        res[pr1 + 1] += (c - pr1 - 1) * (nx1 - c) * v;
        res[c] -= (c - pr1 - 1) * (nx1 - c) * v;
        test << pr1 + 1 _ c _ (c - pr1 - 1) * (nx1 - c) * v<<endl;

        res[c + 1] += (c - pr1) * (nx1 - c - 1) * v;
        res[nx1] -= (c - pr1) * (nx1 - c - 1) * v;
        test << c + 1 _ nx1 _ (c - pr1) * (nx1 - c - 1) * v<<endl;
        
        res[pr1] += (c - pr2 - 1) * (nx1 - c) * v;
        res[pr1 + 1] -= (c - pr2 - 1) * (nx1 - c) * v;
        test << pr1 _ pr1+1 _ (c - pr2) * (nx1 - c) * v<<endl;

        res[nx1] += (c - pr1) * (nx2 - c - 1) * v;
        res[nx1 + 1] -= (c - pr1) * (nx2 - c - 1) * v;
        test << nx1 _ nx1 + 1 _ (c - pr1) * (nx2 - c) * v<<endl;

        for (ll i1 = 0;i1 <= n+2;i1++) test << res[i1] << " ";
        test << endl;
    }
    for (i = 0;i <= n;i++) test << res[i] << " ";
    test << endl;
    c = res[0];
    for (i = 1;i <= n;i++) {

        c += res[i];
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}