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
    ll n, k, kt, i, j, t, s = 0, res = 0, c = 0, neg = 0;
    cin >> n >> kt;
    multiset < pair < ll, ll > > st;
    multiset < pair < ll, ll > >::iterator it;
    pair < ll, ll > pr;
    for (i = 0;i < n;i++) {
        cin >> k;
        st.insert({ k+1, 0 });
    }
    for (i = 0;i < n;i++) {
        cin >> k;
        st.insert({ k+1, 1 });
    }
    c = n;
    for (it = st.begin();it != st.end();) {
        k = it->ff;
        t = 0;
        if (neg <= kt) res = max(res, c * (k-1));
        while (it != st.end() && k == it->ff) {
            if (it->ss) {
                c--;
                neg--;
            } else {
                neg++;
            }
            it++;
        }
        if (neg <= kt) res = max(res, c * k );
        if(it==st.end()) break;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}