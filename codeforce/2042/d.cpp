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
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    ll n, i, j, k, s = 0, l, r, t;
    cin >> n;
    vector < pair < ll, pair < ll, ll> > > a(n), c(n);
    vector < pair < ll, ll > > b(n, { -1, -1 }), d(n);
    map < pair <ll, ll >, int > cnt;
    pair<ll, ll> pr;
    for (i = 0;i < n;i++) {
        cin >> l >> r;
        cnt[{l, r}]++;
        d[i] = { l, r };
        a[i] = { l, {-r, i } };
        c[i] = { r, {-l, i } };
    }
    sort(ALL(c));
    stack< pair<ll, ll> > st;
    for (i = 0;i < n;i++) {
        // test<<"eend" _ i _ c[i]
        while (!st.empty() && st.top().ff >= -c[i].ss.ff) {
            pr = st.top();
            st.pop();
            b[pr.ss].ss = c[i].ff;
        }
        st.push({ -c[i].ss.ff, c[i].ss.ss });
    }
    while (!st.empty()) {
        st.pop();
    }
    sort(ALL(a));
    for (i = n - 1;i >= 0;i--) {
        while (!st.empty() && st.top().ff <= -a[i].ss.ff) {
            pr = st.top();
            st.pop();
            b[pr.ss].ff = a[i].ff;
        }
        st.push({ -a[i].ss.ff, a[i].ss.ss });
    }
    for (i = 0;i < n;i++) {
        // if(b[i].ff==-1 && b[i].ss!=-1){
        //     cout<<i _ b[i].ff _ b[i].ss _ "error\n";

        // }
        // if(b[i].ss==-1 && b[i].ff!=-1){
        //     cout<<i _ b[i].ff _ b[i].ss _ "error\n";

        // }
        if (b[i].ff == -1 || b[i].ss == -1) cout << 0 << endl;
        else {
            // cout << i _ b[i].ff _ b[i].ss _ d[i].ff _ d[i].ss << endl;
            if(cnt[d[i]]>1) cout<<0<<endl;
            else cout << (b[i].ss - b[i].ff) - (d[i].ss - d[i].ff) << endl;
        }
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}